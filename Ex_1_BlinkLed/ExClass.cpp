#include "ExClass.h"

void Blinker::Execute(unsigned onTime_in_ms, unsigned offTime_in_ms, unsigned numberofTime)
{
	onTime = onTime_in_ms;
	offTime = offTime_in_ms;
	NuOfTime = numberofTime;
	pBL->TurnOn();
	Count = true;
	LedState = true;
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
			if (LedState == true)
			{
				if (tick == onTime)
				{
					pBL->TurnOff();
					Count = false;
				}
			}	
		}
		if (NuOfTime > 1)
		{
			if (LedState == true)
			{
				if (tick == onTime)
				{
					pBL->TurnOff();
					LedState = false;
					tick = 0;
					NuOfTime--;
				}
			}
			else
			{
				if (LedState == false)
				{
					if (tick == offTime)
					{
						pBL->TurnOn();
						LedState = true;
						tick = 0;
					}
				}
			}
		}
	}
}


