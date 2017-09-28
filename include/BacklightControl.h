#ifndef _BACKLIGHT_CONTROL_H_
#define _BACKLIGHT_CONTROL_H_

#include "GPIOHandler.h"
#include "vmdcl_pwm.h"

class BacklightControl
{
private:
	unsigned char backlightLevel;
	GPIOHandler backlightPin;
	VM_DCL_HANDLE pwm_handle;
	vm_dcl_pwm_set_clock_t clock;
	vm_dcl_pwm_set_counter_threshold_t counter;


	BacklightControl();
	~BacklightControl();
public:
	BacklightControl(BacklightControl const&) = delete;
	void operator=(BacklightControl const&) = delete;
	static BacklightControl& getInstance();
	void setBacklight(unsigned char level);
	void backlightOn();
	void backlightOff();
};

#endif
