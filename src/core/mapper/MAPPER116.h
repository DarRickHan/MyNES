class MAPPER116 : public MAPPER
{
public:
	MAPPER116(NES* parent);

	void Reset();
	void WriteLow(WORD address, BYTE data);
	void Write(WORD address, BYTE data);

	void HSync(INT scanline);

	BOOL IsStateSave();
	void SaveState(LPBYTE p);
	void LoadState(LPBYTE p);

protected:
	BYTE reg[8];
	BYTE prg0;
	BYTE prg1;
	BYTE prg2;
	BYTE prg3;
	BYTE prg0L;
	BYTE prg1L;
	BYTE chr0;
	BYTE chr1;
	BYTE chr2;
	BYTE chr3;
	BYTE chr4;
	BYTE chr5;
	BYTE chr6;
	BYTE chr7;
	BYTE irq_enable;
	INT irq_counter;
	BYTE irq_latch;
	BYTE ExPrgSwitch;
	BYTE ExChrSwitch;

private:
	void SetBank_CPU();
	void SetBank_PPU();
};