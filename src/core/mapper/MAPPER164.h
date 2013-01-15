class MAPPER164 : public MAPPER
{
public:
	MAPPER164(NES* parent);

	void Reset();
	void WriteLow(WORD address, BYTE data);

	void PPU_ExtLatchX(INT x);
	void PPU_ExtLatch(WORD address, BYTE& chr_l, BYTE& chr_h, BYTE& attr);

	BOOL IsStateSave();
	void SaveState(LPBYTE p);
	void LoadState(LPBYTE p);

protected:
	BYTE reg5000;
	BYTE reg5100;
	BYTE a3;
	BYTE p_mode;

private:
	void SetBank_CPU();
	void SetBank_PPU();
};