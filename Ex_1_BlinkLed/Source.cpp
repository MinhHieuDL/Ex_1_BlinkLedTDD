#include <stdio.h>
#include <iostream>
#include "ExClass.h"
#include <Windows.h>

using namespace std;
class DemoLed : public Iled
{
	virtual void TurnOn()
	{
		printf("Led is on\n");
	}
	virtual void TurnOff()
	{
		printf("Led is off\n");
	}
};

int main(void)
{
	Blinker blinker;
	DemoLed demoLed;
	blinker.AttachLedHAL(&demoLed);

	blinker.Execute(10, 10, 0);
	while (true)
	{
		for (int i = 0; i < 100; i++)
		{
			blinker.Tick1ms();
			Sleep(100);
		}
		printf("Call blinker.Execute(10,10,2)\n");
		blinker.Execute(10, 10, 2);
		for (int i = 0; i < 100; i++)
		{
			blinker.Tick1ms();
			Sleep(100);
		}
	}
	return 0;
}