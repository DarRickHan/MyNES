class MAPPER193 : public MAPPER
{
public:
	MAPPER193(NES* parent);

	void Reset();
	void WriteLow(WORD address, BYTE data);

protected:
};