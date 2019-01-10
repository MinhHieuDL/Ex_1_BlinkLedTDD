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
		void callTick1ms(unsigned int times)
		{
			for (unsigned i = 0; i < times; i++)
			{
				B.Tick1ms();
			}
		}
		void CheckLedIsOFF(unsigned int onTime)
		{
			callTick1ms(onTime);
			Assert::IsTrue(LedIsON == 0);
		}
		void CheckLedIsON(unsigned int offTime)
		{
			callTick1ms(offTime);
			Assert::IsTrue(LedIsON == 1);
		}
	public:
		TEST_METHOD(canBlinkOneTime)
		{
			B.AttachLedHAL(&fakeLed);
			B.Execute(100, 200, 1);
			Assert::IsTrue(LedIsON == 1);
			CheckLedIsOFF(100);
		}

		TEST_METHOD(canBlinkTwoTimes)
		{
			B.AttachLedHAL(&fakeLed);
			B.Execute(100, 200, 2);
			Assert::IsTrue(LedIsON == 1);
			CheckLedIsOFF(100);
			CheckLedIsON(200);
			CheckLedIsOFF(100);
		}

		TEST_METHOD(canBlinkForever)
		{
			B.AttachLedHAL(&fakeLed);
			B.Execute(100, 200, 0);
			Assert::IsTrue(LedIsON == 1);
			for (unsigned i = 0; i < 100; i++)
			{
				CheckLedIsOFF(100);
				CheckLedIsON(200);
			}
		}

		TEST_METHOD(canSTOP)
		{
			B.AttachLedHAL(&fakeLed);
			B.Execute(100, 200, 0);
			Assert::IsTrue(LedIsON == 1);
			B.Stop();
			for (unsigned i = 0; i < 10000; i++)
			{
				B.Tick1ms();
				Assert::IsTrue(LedIsON == 0);
			}
		}
	};
}