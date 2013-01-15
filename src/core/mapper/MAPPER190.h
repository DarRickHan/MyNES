class MAPPER190 : public MAPPER
{
public:
	MAPPER190(NES* parent);

	void Reset();
	void Write(WORD address, BYTE data);
	BYTE ReadLow(WORD address);
	void WriteLow(WORD address, BYTE data);

	void HSync(INT scanline);

	BOOL IsStateSave();
	void SaveState(LPBYTE p);
	void LoadState(LPBYTE p);

protected:
	BYTE cbase;
	BYTE mp190_lcchk;
	BYTE mp190_lcmd;
	BYTE mp190_cmd;
	BYTE irq_enable;
	BYTE irq_counter;
	BYTE irq_latch;
	BYTE lowoutdata;
};