
class Iled
{
public:
	virtual void TurnOn() = 0;
	virtual void TurnOff() = 0;
};


class Blinker
{
private:
	Iled *pBL;
	unsigned int tick, onTime, offTime, numberOfTime, ledState;
	bool countEnable, blinkForeverFlag, stopFlag;
	void blinkOneTime(void);
	void blinkMultiTimes(void);
	void blinkForever(void);
	void turnOffLed(void);
	void turnOnLed(void);
public:
	class Blinker() : tick(0)
	{
		countEnable = false;
		blinkForeverFlag = false;
		stopFlag = false;
		ledState = 0;
		onTime = 0;
		offTime = 0;
		numberOfTime = 0;
	}

	void Execute(unsigned onTime_in_ms, unsigned offTime_in_ms, unsigned numberofTime);
	void Stop(void);
	void AttachLedHAL(Iled * pLed);
	void Tick1ms(void);
};