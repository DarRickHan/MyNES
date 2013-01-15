class MAPPER236 : public MAPPER
{
public:
	MAPPER236(NES* parent);

	void Reset();
	void Write(WORD address, BYTE data);

	BOOL IsStateSave();
	void SaveState(LPBYTE p);
	void LoadState(LPBYTE p);

protected:
	BYTE bank;
	BYTE mode;
};