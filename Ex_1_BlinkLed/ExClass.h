
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
	unsigned int tick, onTime, offTime, NuOfTime, LedState;
	bool Count, BlForever;
	void BlinkOneTime(void);
	void BlinkMultiTimes(void);
	void BlinkForever(void);
	void TurnOffLed(void);
	void TurnOnLed(void);
public:
	class Blinker() : tick(0)
	{
		Count = false;
		BlForever = false;
		LedState = 0;
		onTime = 0;
		offTime = 0;
		NuOfTime = 0;
	}

	void Execute(unsigned onTime_in_ms, unsigned offTime_in_ms, unsigned numberofTime);
	void AttachLedHAL(Iled * pLed);
	void Tick1ms(void);

};