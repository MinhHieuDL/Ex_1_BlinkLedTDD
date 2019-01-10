#include "ExClass.h"

void Blinker::Execute(unsigned onTime_in_ms, unsigned offTime_in_ms, unsigned numberofTime)
{
	stopFlag = false;
	tick = 0;
	onTime = onTime_in_ms;
	offTime = offTime_in_ms;
	numberOfTime = numberofTime;
	pBL->TurnOn();
	ledState = 1;
	countEnable = true;
	if (numberofTime == 0) blinkForeverFlag = true;
	else blinkForeverFlag = false;
}

void Blinker::AttachLedHAL(Iled * pLed)
{
	pBL = pLed;
}

void Blinker::Tick1ms(void)
{
	if (countEnable == true)
	{
		tick++;
		if (stopFlag == true)
		{
			turnOffLed();
			countEnable = false;
		}
		else
		{
			switch (blinkForeverFlag)
			{
			case true:
				blinkForever();
				break;
			case false:
				if (numberOfTime == 1)
					blinkOneTime();
				else if (numberOfTime > 1)
					blinkMultiTimes();
			default:
				break;
			}
		}
	}
}

void Blinker::blinkOneTime(void)
{
	if (ledState == 1)
	{
		if (tick == onTime)
		{
			turnOffLed();
			countEnable = false;
		}
	}
	else if (ledState == 0)
	{
		if (tick == offTime)
			turnOnLed();
	}
}

void Blinker::blinkMultiTimes(void)
{
	if (ledState == 1)
	{
		if (tick == onTime)
		{
			turnOffLed();
			numberOfTime--;
		}
	}
	else if (ledState == 0)
	{
		if (tick == offTime)
			turnOnLed();
	}
}

void Blinker::blinkForever(void)
{
	if (ledState == 1)
	{
		if (tick == onTime)
			turnOffLed();
	}
	else if (ledState == 0)
	{
		if (tick == offTime)
			turnOnLed();
	}
}

void Blinker::turnOffLed(void)
{
	pBL->TurnOff();
	ledState = 0;
	tick = 0;
}

void Blinker::turnOnLed(void)
{
	pBL->TurnOn();
	ledState = 1;
	tick = 0;
}

void Blinker::Stop(void)
{
	stopFlag = true;
}
