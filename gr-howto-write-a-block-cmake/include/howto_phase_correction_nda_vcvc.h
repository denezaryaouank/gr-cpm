#ifndef INCLUDED_HOWTO_PHASE_CORRECTION__NDA_VCVC_H
#define INCLUDED_HOWTO_PHASE_CORRECTION_NDA_VCVC_H

#include <howto_api.h>
#include <gr_core_api.h>
#include <gr_sync_block.h>
#include <gri_control_loop.h>
#include <digital_constellation.h>

class howto_phase_correction_nda_vcvc;
typedef boost::shared_ptr<howto_phase_correction_nda_vcvc> howto_phase_correction_nda_vcvc_sptr;
HOWTO_API howto_phase_correction_nda_vcvc_sptr howto_make_phase_correction_nda_vcvc (unsigned int lvec, unsigned int power, float loop_bw, float max_freq, float min_freq);


class HOWTO_API howto_phase_correction_nda_vcvc: public gr_sync_block, public gri_control_loop
{
private:
friend HOWTO_API howto_phase_correction_nda_vcvc_sptr howto_make_phase_correction_nda_vcvc(unsigned int lvec, unsigned int power, float loop_bw, float max_freq, float min_freq);
howto_phase_correction_nda_vcvc(unsigned int lvec, unsigned int power, float loop_bw, float max_freq, float min_freq);
unsigned int d_power;
unsigned int d_lvec;
public:
virtual float phase_detector(gr_complex sample, float ref_phase);
virtual float mod_2pi(float in_ph);
int work(int noutput_items,
	gr_vector_const_void_star &input_items,
	gr_vector_void_star &output_items);
};

#endif