class MAPPER142 : public MAPPER
{
public:
	MAPPER142(NES* parent);

	void Reset();
	void Write(WORD address, BYTE data);

	void HSync(INT scanline);

	BOOL IsStateSave();
	void SaveState(LPBYTE p);
	void LoadState(LPBYTE p);

protected:
	BYTE prg_sel;
	BYTE irq_enable;
	INT irq_counter;
};