#include "ExClass.h"

void Blinker::Execute(unsigned onTime_in_ms, unsigned offTime_in_ms, unsigned numberofTime)
{
	onTime = onTime_in_ms;
	offTime = offTime_in_ms;
	if (numberofTime == 1)
	{
		pBL->TurnOn();
		Count = true;
	}
}

void Blinker::AttachLedHAL(Iled * pLed)
{
	pBL = pLed;
}

void Blinker::Tick1ms(void)
{
	if (Count == true)
	{
		tick++;
		if (tick == onTime)
			pBL->TurnOff();
	}
}


