class MAPPER032 : public MAPPER
{
public:
	MAPPER032(NES* parent);

	void Reset();
	void Write(WORD address, BYTE data);

	BOOL IsStateSave();
	void SaveState(LPBYTE p);
	void LoadState(LPBYTE p);

protected:
	BYTE patch;
	BYTE reg;
};