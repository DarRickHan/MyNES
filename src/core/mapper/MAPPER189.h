class MAPPER189 : public MAPPER
{
public:
	MAPPER189(NES* parent);

	void Reset();
	void WriteLow(WORD address, BYTE data);
	void Write(WORD address, BYTE data);
	void HSync(INT scanline);

	BOOL IsStateSave();
	void SaveState(LPBYTE p);
	void LoadState(LPBYTE p);

protected:
	BYTE patch;
	BYTE reg[2];
	BYTE chr01;
	BYTE chr23;
	BYTE chr4;
	BYTE chr5;
	BYTE chr6;
	BYTE chr7;
	BYTE irq_enable;
	BYTE irq_counter;
	BYTE irq_latch;
	BYTE protect_dat[4];
	BYTE lwd;

private:
	void SetBank_CPU();
	void SetBank_PPU();
};