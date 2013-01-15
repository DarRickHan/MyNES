class MAPPER243 : public MAPPER
{
public:
	MAPPER243(NES* parent);

	void Reset();
	void WriteLow(WORD address, BYTE data);

	BOOL IsStateSave();
	void SaveState(LPBYTE p);
	void LoadState(LPBYTE p);

protected:
	BYTE reg[4];
};