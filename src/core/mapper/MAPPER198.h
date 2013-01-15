class MAPPER198 : public MAPPER
{
public:
	MAPPER198(NES* parent);

	void Reset();
	void Write(WORD address, BYTE data);
	BYTE ReadLow(WORD address);
	void WriteLow(WORD address, BYTE data);

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
	BYTE adr5000buf[1024*4];

private:
	void SetBank_CPU();
	void SetBank_PPU();
};