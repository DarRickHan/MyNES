class MAPPER254 : public MAPPER
{
public:
	MAPPER254(NES* parent);

	void Reset();
	void Write(WORD address, BYTE data);
	BYTE ReadLow(WORD address);
	void WriteLow(WORD address, BYTE data);

	void Clock(INT cycles);
	void HSync(INT scanline);

	BOOL IsStateSave();
	void SaveState(LPBYTE p);
	void LoadState(LPBYTE p);

protected:
	BYTE reg[8];
	BYTE prg0;
	BYTE prg1;
	BYTE chr01;
	BYTE chr23;
	BYTE chr4;
	BYTE chr5;
	BYTE chr6;
	BYTE chr7;
	BYTE irq_type;
	BYTE irq_enable;
	BYTE irq_counter;
	BYTE irq_latch;
	BYTE irq_request;
	BYTE protectflag;

private:
	void SetBank_CPU();
	void SetBank_PPU();
};