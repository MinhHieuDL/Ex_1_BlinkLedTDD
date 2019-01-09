#include "ExClass.h"

void Blinker::Execute(unsigned onTime_in_ms, unsigned offTime_in_ms, unsigned numberofTime)
{
	tick = 0;
	onTime = onTime_in_ms;
	offTime = offTime_in_ms;
	NuOfTime = numberofTime;
	pBL->TurnOn();
	LedState = 1;
	Count = true;
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
		if (NuOfTime == 1)
		{
			BlinkOneTime();
		}
		else if (NuOfTime > 1)
		{
			BlinkMultiTimes();
		}
	}
}

void Blinker::BlinkOneTime(void)
{
	if (LedState == 1)
	{
		if (tick == onTime)
		{
			TurnOffLed();
			Count = false;
		}
	}
	else if (LedState == 0)
	{
		if (tick == offTime)
		{
			TurnOnLed();
		}
	}
}

void Blinker::BlinkMultiTimes(void)
{
	if (LedState == 1)
	{
		if (tick == onTime)
		{
			TurnOffLed();
			NuOfTime--;
		}
	}
	else if (LedState == 0)
	{
		if (tick == offTime)
		{
			TurnOnLed();
		}
	}
}

void Blinker::TurnOffLed(void)
{
	pBL->TurnOff();
	LedState = 0;
	tick = 0;
}

void Blinker::TurnOnLed(void)
{
	pBL->TurnOn();
	LedState = 1;
	tick = 0;
}
