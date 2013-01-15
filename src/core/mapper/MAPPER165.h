class MAPPER165 : public MAPPER
{
public:
	MAPPER165(NES* parent);

	void Reset();
	void Write(WORD address, BYTE data);

	void PPU_ChrLatch(WORD address);

	BOOL IsStateSave();
	void SaveState(LPBYTE p);
	void LoadState(LPBYTE p);

protected:
	BYTE reg[8];
	BYTE prg0;
	BYTE prg1;
	BYTE chr0;
	BYTE chr1;
	BYTE chr2;
	BYTE chr3;
	BYTE we_sram;
	BYTE latch;

private:
	void SetBank_CPU();
	void SetBank_PPU();
	void SetBank_PPUSUB(INT bank, INT page);
};