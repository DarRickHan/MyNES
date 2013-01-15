class MAPPER191 : public MAPPER
{
public:
	MAPPER191(NES* parent);

	void Reset();
	void WriteLow(WORD address, BYTE data);

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
	BYTE highbank;

private:
	void SetBank_CPU();
	void SetBank_PPU();
};