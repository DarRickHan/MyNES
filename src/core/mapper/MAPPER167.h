class MAPPER167 : public MAPPER
{
public:
	MAPPER167(NES* parent);

	void Reset();
	void Write(WORD address, BYTE data);

	BOOL IsStateSave();
	void SaveState(LPBYTE p);
	void LoadState(LPBYTE p);

protected:
	BYTE regs[4];
	BYTE rom_type;

private:
	void SetBank_CPU();
	void SetBank_PPU();
};