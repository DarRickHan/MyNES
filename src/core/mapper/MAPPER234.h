class MAPPER234 : public MAPPER
{
public:
	MAPPER234(NES* parent);

	void Reset();
	void Write(WORD address, BYTE data);
	void Read(WORD address, BYTE data);

	BOOL IsStateSave();
	void SaveState(LPBYTE p);
	void LoadState(LPBYTE p);

protected:
	BYTE reg[2]

private:
	void SetBank();
};