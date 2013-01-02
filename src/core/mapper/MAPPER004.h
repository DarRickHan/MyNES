class MAPPER004 : public MAPPER
{
public:
	MAPPER004(NES* parent);

	void Reset();
	BYTE ReadLow(WORD address);
	void WriteLow(WORD address, BYTE data);
	void Write(WORD address, BYTE data);

	void HSync(INT scanline);

	BOOL IsStateSave();
	void SaveState(LPBYTE p);
	void LoadState(LPBYTE p);

protected:
	BYTE reg[8];
	BYTE prg0;
	BYTE prg1;
	BYTE chr01;
	BYTE chr23;
	BYTE chr4;
	BYTE chr5;
	BYTE chr6;
	BYTE chr7;
	BYTE we_sram;
	BYTE irq_type;
	BYTE irq_enable;
	BYTE irq_counter;
	BYTE irq_latch;
	BYTE irq_request;
	BYTE irq_preset;
	BYTE irq_preset_vbl;
	BYTE vs_patch;
	BYTE vs_index;

private:
	void SetBank_CPU();
	void SetBank_PPU();
};