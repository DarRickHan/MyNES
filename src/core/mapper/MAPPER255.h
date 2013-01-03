class MAPPER255 : public MAPPER
{
public:
	MAPPER255(NES* parent);

	void Reset();
	BYTE ReadLow(WORD address, BYTE data);
	void WriteLow(WORD address, BYTE data);
	void Write(WORD address, BYTE data);

	BOOL IsStateSave();
	void SaveState(LPBYTE p);
	void LoadState(LPBYTE p);

protected:
	BYTE reg[4];
};