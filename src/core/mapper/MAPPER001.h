class MAPPER001 : public MAPPER
{
public:
	MAPPER001(NES* parent);

	void Reset();
	void Write(WORD address, BYTE data);

	BOOL IsStateSave();
	void SaveState(LPBYTE p);
	void LoadState(LPBYTE p);

protected:
	WORD last_address;
	BYTE patch;
	BYTE wram_patch;
	BYTE wram_bank;
	BYTE wram_count;
	BYTE reg[4];
	BYTE shift;
	BYTE regbuf;
};