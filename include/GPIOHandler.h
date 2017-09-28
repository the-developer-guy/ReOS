#ifndef _GPIO_HANDLER_H_
#define _GPIO_HANDLER_H_

#include "vmdcl.h"
#include "vmdcl_gpio.h"
#include "vmboard.h"
#include "pindefinition.h"

#define GPIO_OUTPUT true
#define GPIO_INPUT false

#define GPIO_HIGH	true
#define GPIO_LOW	false

#define GPIO_PULL_UP 2
#define GPIO_PULL_DOWN 1
#define GPIO_PULL_OFF 0

class GPIOHandler
{
private:
	VM_DCL_HANDLE ioHandler;
	bool direction;
	int pullup;
public:
	GPIOHandler();
	~GPIOHandler();
	GPIOHandler(int io);
	GPIOHandler(int io, bool direction, int pullup = GPIO_PULL_OFF, bool value = GPIO_LOW, VM_DCL_PIN_MODE mode = VM_DCL_PIN_MODE_GPIO);
	VM_DCL_STATUS setDirection(int direction);
	VM_DCL_STATUS setLevel(bool level);
	VM_DCL_STATUS setPullup(int pullup);
	bool getLevel();
};

#endif
