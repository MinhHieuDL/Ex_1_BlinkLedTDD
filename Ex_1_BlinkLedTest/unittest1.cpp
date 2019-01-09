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
			B.AttachLedHAL(&fakeLed);
			B.Execute(100, 200, 1);
			Assert::IsTrue(LedIsON == 1);
			for (unsigned i = 0; i < 100; i++)
			{
				B.Tick1ms();
			}
			Assert::IsTrue(LedIsON == 0);
		}

		TEST_METHOD(canBlinkTwoTimes)
		{
			B.AttachLedHAL(&fakeLed);
			B.Execute(100, 200, 2);
			Assert::IsTrue(LedIsON == 1);
			for(unsigned int j = 0; j < 100; j++)
				B.Tick1ms();
			Assert::IsTrue(LedIsON == 0);
			for (unsigned int k = 0; k < 200; k++)
				B.Tick1ms();
			Assert::IsTrue(LedIsON == 1);
			for (unsigned int j = 0; j < 100; j++)
				B.Tick1ms();
			Assert::IsTrue(LedIsON == 0);
		}
	};
}