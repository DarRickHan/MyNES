class MAPPER251 : public MAPPER
{
public:
	MAPPER251(NES* parent);

	void Reset();
	void WriteLow(WORD address, BYTE data);
	void Write(WORD address, BYTE data);

	BOOL IsStateSave();
	void SaveState(LPBYTE p);
	void LoadState(LPBYTE p);

protected:
	BYTE reg[11];
	BYTE breg[4];

private:
	void SetBank();
};