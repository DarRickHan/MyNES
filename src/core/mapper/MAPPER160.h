class MAPPER160 : public MAPPER
{
public:
	MAPPER160(NES* parent);

	void Reset();
	void Write(WORD address, BYTE data);

	void HSync(INT scanline);

	BOOL IsStateSave();
	void SaveState(LPBYTE p);
	void LoadState(LPBYTE p);

protected:
	BYTE irq_enable;
	BYTE irq_counter;
	BYTE irq_latch;
	BYTE refresh_type;
};