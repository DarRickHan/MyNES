class MAPPER183 : public MAPPER
{
public:
	MAPPER183(NES* parent);

	void Reset();
	void Write(WORD address, BYTE data);

	void HSync(INT scanline);

	BOOL IsStateSave();
	void SaveState(LPBYTE p);
	void LoadState(LPBYTE p);

protected:
	BYTE reg[8];
	BYTE irq_enable;
	INT irq_counter;
};