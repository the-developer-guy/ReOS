#ifndef _STATUS_LED_H_
#define _STATUS_LED_H_

#include "GPIOHandler.h"

enum Color
{
	off = 0,
	red,
	green,
	blue,
	yellow,
	purple,
	cyan,
	white
};

class StatusLed
{
private:
	GPIOHandler ledRed;
	GPIOHandler ledGreen;
	GPIOHandler ledBlue;


	StatusLed();
	~StatusLed();
public:
	StatusLed(StatusLed const&) = delete;
	void operator=(StatusLed const&) = delete;
	static StatusLed& getInstance();
	void setColor(Color color);
};

#endif
