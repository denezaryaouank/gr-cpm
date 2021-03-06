load x;
plot(x);
ub=(x>0.1);
x_n=zeros(2,length(ub));
v_n=0;
v_np1=0;
psi_n=zeros(2,length(ub));
s_xn=zeros(2,length(ub));
for k=1:length(ub)
    u_n=ub(k);
    v_n=v_np1;
    s_n=v_n;
    x_n(1,k)=u_n;
    x_n(2,k)=s_n;
    v_np1=mod(v_n+u_n,2);
    psi_n(1,k)=(pi*v_n+pi/2);
    psi_n(2,k)=pi*u_n; %T=1
    s_xn(1,k)=exp(1i*psi_n(1,k));
    s_xn(2,k)=exp(1i*psi_n(2,k)); %s_xn(k)=s_xn(1,k)*(s_xn(2,k)^tau)
end 
