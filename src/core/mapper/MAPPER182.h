class MAPPER182 : public MAPPER
{
public:
	MAPPER182(NES* parent);

	void Reset();
	void Write(WORD address, BYTE data);

	void HSync(INT scanline);

	BOOL IsStateSave();
	void SaveState(LPBYTE p);
	void LoadState(LPBYTE p);

protected:
	BYTE reg;
	BYTE irq_enable;
	BYTE irq_counter;
};