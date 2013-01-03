class MAPPER252 : public MAPPER
{
public:
	MAPPER252(NES* parent);

	void Reset();
	void Write(WORD address, BYTE data);

	void Clock(INT cycles);

	BOOL IsStateSave();
	void SaveState(LPBYTE p);
	void LoadState(LPBYTE p);

protected:
	BYTE reg[9];
	BYTE irq_enable;
	BYTE irq_counter;
	BYTE irq_latch;
	BYTE irq_occur;
	INT irq_clock;
};