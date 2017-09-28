#include "GPIOHandler.h"


GPIOHandler::GPIOHandler(int io)
{
	ioHandler = vm_dcl_open(VM_DCL_GPIO, io);
	vm_dcl_control(ioHandler, VM_DCL_GPIO_COMMAND_SET_MODE_0, NULL);
	vm_dcl_control(ioHandler,VM_DCL_GPIO_COMMAND_SET_DIRECTION_OUT, NULL);
	vm_dcl_control(ioHandler,VM_DCL_GPIO_COMMAND_WRITE_HIGH, NULL);
}

GPIOHandler::GPIOHandler(int io, bool direction, int pullup, bool value, VM_DCL_PIN_MODE mode)
{
	this->direction = direction;
	this->pullup = pullup;
	ioHandler = vm_dcl_open(VM_DCL_GPIO, io);
	vm_dcl_config_pin_mode(io, mode);
	if(mode == VM_DCL_PIN_MODE_GPIO)
	{
		switch(direction)
		{
		case GPIO_OUTPUT:
			setDirection(GPIO_OUTPUT);
			setPullup(GPIO_PULL_OFF);
			setLevel(value);
			direction = true;
			break;
		default:
		case GPIO_INPUT:
			setDirection(GPIO_INPUT);
			setPullup(pullup);
			direction = false;
			break;
		}
	}
}

GPIOHandler::~GPIOHandler()
{
	vm_dcl_close(ioHandler);
}

VM_DCL_STATUS GPIOHandler::setDirection(int direction)
{
	if(GPIO_OUTPUT)
	{
		return vm_dcl_control(ioHandler,VM_DCL_GPIO_COMMAND_SET_DIRECTION_OUT, NULL);
	}
	else if(GPIO_INPUT)
	{
		return vm_dcl_control(ioHandler,VM_DCL_GPIO_COMMAND_SET_DIRECTION_IN, NULL);
	}
	else
	{
		return VM_DCL_STATUS_INVALID_CONTROL_DATA;
	}
}

VM_DCL_STATUS GPIOHandler::setLevel(bool level)
{
	if(level)
	{
		return vm_dcl_control(ioHandler,VM_DCL_GPIO_COMMAND_WRITE_HIGH, NULL);
	}
	else
	{
		return vm_dcl_control(ioHandler,VM_DCL_GPIO_COMMAND_WRITE_LOW, NULL);
	}
}

VM_DCL_STATUS GPIOHandler::setPullup(int pullup)
{
	VM_DCL_STATUS retval = VM_DCL_STATUS_OK;
	switch(pullup)
	{
	case GPIO_PULL_UP:
		retval = vm_dcl_control(ioHandler, VM_DCL_GPIO_COMMAND_ENABLE_PULL, NULL);
		if(retval == VM_DCL_STATUS_OK )
		{
			return vm_dcl_control(ioHandler, VM_DCL_GPIO_COMMAND_SET_PULL_HIGH, NULL);
		}
		else
		{
			return retval;
		}
	case GPIO_PULL_DOWN:
		retval = vm_dcl_control(ioHandler,VM_DCL_GPIO_COMMAND_ENABLE_PULL, NULL);
		if(retval == VM_DCL_STATUS_OK )
		{
			return vm_dcl_control(ioHandler,VM_DCL_GPIO_COMMAND_SET_PULL_LOW, NULL);
		}
	default:
	case GPIO_PULL_OFF:
		return vm_dcl_control(ioHandler,VM_DCL_GPIO_COMMAND_DISABLE_PULL, NULL);
	}
}

bool GPIOHandler::getLevel()
{
	if(direction == GPIO_INPUT)
	{
		vm_dcl_gpio_control_level_status_t gpio_input_data;
		if(vm_dcl_control(ioHandler, VM_DCL_GPIO_COMMAND_READ, (void *)&gpio_input_data) == VM_DCL_STATUS_OK )
		{
			if((int)gpio_input_data.level_status == (int)VM_DCL_GPIO_IO_LOW)
			{
				return GPIO_LOW;
			}
			else
			{
				return GPIO_HIGH;
			}
		}
	}
	else
	{
		return GPIO_LOW;
	}

}
