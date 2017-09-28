#include "BacklightControl.h"

BacklightControl::BacklightControl(): backlightLevel(10),
	backlightPin(PIN_BACKLIGHT, GPIO_OUTPUT, GPIO_PULL_OFF, GPIO_LOW, VM_DCL_PIN_MODE_PWM)
//(int io, bool direction, int pullup, bool value, VM_DCL_PIN_MODE mode)
{
	//backlightLevel = 200;
	//backlightPin = GPIOHandler(PIN_BACKLIGHT);
	pwm_handle = vm_dcl_open(PIN2PWM(PIN_BACKLIGHT), vm_dcl_get_owner_id());
	vm_dcl_control(pwm_handle,VM_PWM_CMD_START, 0);
	clock.source_clock = 0;
	clock.source_clock_division = 3;
	counter.counter = 255;
	counter.threshold = backlightLevel;
	vm_dcl_control(pwm_handle,VM_PWM_CMD_SET_CLOCK,(void *)(&clock));
	vm_dcl_control(pwm_handle,VM_PWM_CMD_SET_COUNTER_AND_THRESHOLD,(void *)(&counter));
}

BacklightControl::~BacklightControl()
{
	//vm_dcl_close(pwm_handle);
}

static BacklightControl& BacklightControl::getInstance()
{
	static BacklightControl instance;
	return instance;
}

void BacklightControl::setBacklight(unsigned char level)
{
	backlightLevel = level;
}
void BacklightControl::backlightOn()
{
	//vm_dcl_control(pwm_handle, VM_PWM_CMD_SET_LEVEL, (void *)(&backlightLevel));
}

void BacklightControl::backlightOff()
{
	//vm_dcl_control(pwm_handle, VM_PWM_CMD_SET_LEVEL, (void *)(0));
}
