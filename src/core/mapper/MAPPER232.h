class MAPPER232 : public MAPPER
{
public:
	MAPPER232(NES* parent);

	void Reset();
	void WriteLow(WORD address, BYTE data);
	void Write(WORD address, BYTE data);

	BOOL IsStateSave();
	void SaveState(LPBYTE p);
	void LoadState(LPBYTE p);

protected:
	BYTE reg[2];
};