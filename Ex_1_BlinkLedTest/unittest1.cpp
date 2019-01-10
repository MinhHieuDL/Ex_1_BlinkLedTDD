#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Ex_1_BlinkLed/ExClass.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Ex_1_BlinkLedTest
{	
	class TestLedFake : public Iled
	{
	public:
		bool LedIsON;
		class TestLedFake() : LedIsON(false) {};

		virtual void TurnOn()
		{
			LedIsON = true;
		}
		virtual void TurnOff()
		{
			LedIsON = false;
		}
	};

	TEST_CLASS(UnitTest1)
	{
	private:
		Blinker blinker;
		TestLedFake fakeLed;
#define DIFFERENTIAL 5
		void callTick1ms(unsigned int times)
		{
			for (unsigned i = 0; i < times; i++)
				blinker.Tick1ms();
		}

		void CheckLedIsOFF(unsigned int onTime)
		{
			callTick1ms(onTime - DIFFERENTIAL);
			Assert::IsTrue(fakeLed.LedIsON == true);
			callTick1ms(DIFFERENTIAL);
			Assert::IsTrue(fakeLed.LedIsON == false);
		}

		void CheckLedIsON(unsigned int offTime)
		{
			callTick1ms(offTime - DIFFERENTIAL);
			Assert::IsTrue(fakeLed.LedIsON == false);
			callTick1ms(DIFFERENTIAL);
			Assert::IsTrue(fakeLed.LedIsON == true);
		}
	public:

		TEST_METHOD(canBlinkOneTime)
		{
			blinker.AttachLedHAL(&fakeLed);
			blinker.Execute(100, 200, 1);
			Assert::IsTrue(fakeLed.LedIsON == true);
			CheckLedIsOFF(100);
		}

		TEST_METHOD(canBlinkTwoTimes)
		{
			blinker.AttachLedHAL(&fakeLed);
			blinker.Execute(100, 200, 2);
			Assert::IsTrue(fakeLed.LedIsON == true);
			CheckLedIsOFF(100);
			CheckLedIsON(200);
			CheckLedIsOFF(100);
		}

		TEST_METHOD(canBlinkForever)
		{
			blinker.AttachLedHAL(&fakeLed);
			blinker.Execute(100, 200, 0);
			Assert::IsTrue(fakeLed.LedIsON == true);
			for (unsigned i = 0; i < 100; i++)
			{
				CheckLedIsOFF(100);
				CheckLedIsON(200);
			}
		}

		TEST_METHOD(canSTOP)
		{
			blinker.AttachLedHAL(&fakeLed);
			blinker.Execute(100, 200, 0);
			Assert::IsTrue(fakeLed.LedIsON == true);
			blinker.Stop();
			for (unsigned i = 0; i < 10000; i++)
			{
				blinker.Tick1ms();
				Assert::IsTrue(fakeLed.LedIsON == false);
			}
		}

		TEST_METHOD(callExecuteTwoTimeConsecutive)
		{
			blinker.AttachLedHAL(&fakeLed);
			blinker.Execute(100, 200, 0);
			callTick1ms(5000);
			blinker.Execute(100, 200, 2);
			Assert::IsTrue(fakeLed.LedIsON == true);
			CheckLedIsOFF(100);
			CheckLedIsON(200);
			CheckLedIsOFF(100);
			for (unsigned i = 0; i < 10000; i++)
			{
				blinker.Tick1ms();
				Assert::IsTrue(fakeLed.LedIsON == false);
			}
		}

	};
}