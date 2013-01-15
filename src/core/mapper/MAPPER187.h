class MAPPER187 : public MAPPER
{
public:
	MAPPER187(NES* parent);

	void Reset();
	BYTE ReadLow(WORD address);
	void WriteLow(WORD address, BYTE data);
	void Write(WORD address, BYTE data);

	void Clock(INT cycles);
	void HSync(INT scanline);

	BOOL IsStateSave();
	void SaveState(LPBYTE p);
	void LoadState(LPBYTE p);

protected:
	BYTE prg[4];
	INT chr[8];
	BYTE bank[8];
	BYTE ext_mode;
	BYTE chr_mode;
	BYTE ext_enable;
	BYTE irq_enable;
	BYTE irq_counter;
	BYTE irq_latch;
	BYTE irq_occur;
	BYTE last_write;

private:
	void SetBank_CPU();
	void SetBank_PPU();
};