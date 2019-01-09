#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Ex_1_BlinkLed/ExClass.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Ex_1_BlinkLedTest
{	
	unsigned int LedIsON = 0;

	class TestLedFake : public Iled
	{
		virtual void TurnOn()
		{
			LedIsON = 1;
		}
		virtual void TurnOff()
		{
			LedIsON = 0;
		}
	};

	TEST_CLASS(UnitTest1)
	{
	private:
		Blinker B;
		TestLedFake fakeLed;
	public:
		TEST_METHOD(canBlinkOneTime)
		{
			B.Execute(100, 200, 1);
		}
	};
}