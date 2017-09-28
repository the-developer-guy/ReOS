#include "StatusLed.h"

StatusLed::StatusLed(): ledRed(PIN_LED_RED),
						ledGreen(PIN_LED_GRN),
						ledBlue(PIN_LED_BLU)
{}

StatusLed::~StatusLed(){}

static StatusLed& StatusLed::getInstance()
{
	static StatusLed instance;
	return instance;
}
void StatusLed::setColor(Color color)
{
	switch(color)
	{
	default:
	case off:
		ledRed.setLevel(GPIO_HIGH);
		ledGreen.setLevel(GPIO_HIGH);
		ledBlue.setLevel(GPIO_HIGH);
		break;
	case red:
		ledRed.setLevel(GPIO_LOW);
		ledGreen.setLevel(GPIO_HIGH);
		ledBlue.setLevel(GPIO_HIGH);
		break;
	case green:
		ledRed.setLevel(GPIO_HIGH);
		ledGreen.setLevel(GPIO_LOW);
		ledBlue.setLevel(GPIO_HIGH);
		break;
	case blue:
		ledRed.setLevel(GPIO_HIGH);
		ledGreen.setLevel(GPIO_HIGH);
		ledBlue.setLevel(GPIO_LOW);
		break;
	case yellow:
		ledRed.setLevel(GPIO_LOW);
		ledGreen.setLevel(GPIO_LOW);
		ledBlue.setLevel(GPIO_HIGH);
		break;
	case purple:
		ledRed.setLevel(GPIO_LOW);
		ledGreen.setLevel(GPIO_HIGH);
		ledBlue.setLevel(GPIO_LOW);
		break;
	case cyan:
		ledRed.setLevel(GPIO_HIGH);
		ledGreen.setLevel(GPIO_LOW);
		ledBlue.setLevel(GPIO_LOW);
		break;
	case white:
		ledRed.setLevel(GPIO_LOW);
		ledGreen.setLevel(GPIO_LOW);
		ledBlue.setLevel(GPIO_LOW);
		break;
	}
}
