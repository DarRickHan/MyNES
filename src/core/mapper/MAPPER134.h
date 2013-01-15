class MAPPER134 : public MAPPER
{
public:
	MAPPER134(NES* parent);

	void Reset();
	void WriteLow(WORD address, BYTE data);

	BOOL IsStateSave();
	void SaveState(LPBYTE p);
	void LoadState(LPBYTE p);

protected:
	BYTE cmd;
	BYTE prg;
	BYTE chr;
};