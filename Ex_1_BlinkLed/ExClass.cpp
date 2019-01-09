#include "ExClass.h"

void Blinker::Execute(unsigned onTime_in_ms, unsigned offTime_in_ms, unsigned numberofTime)
{
}

void Blinker::AttachLedHAL(Iled * pLed)
{
	pBL = pLed;
}
