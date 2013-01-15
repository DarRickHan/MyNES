class MAPPER135 : public MAPPER
{
public:
	MAPPER135(NES* parent);

	void Reset();
	void WriteLow(WORD address, BYTE data);

	BOOL IsStateSave();
	void SaveState(LPBYTE p);
	void LoadState(LPBYTE p);

protected:
	BYTE cmd;
	BYTE chr01;
	BYTE chr1l;
	BYTE chr0h;
	BYTE chr1h;
	BYTE chrch;

private:
	void SetBank_PPU();
};