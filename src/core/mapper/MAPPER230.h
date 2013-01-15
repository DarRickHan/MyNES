class MAPPER230 : public MAPPER
{
public:
	MAPPER230(NES* parent);

	void Reset();
	void Write(WORD address, BYTE data);

protected:
	BYTE row_sw;
};