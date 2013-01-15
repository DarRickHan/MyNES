class MAPPER122 : public MAPPER
{
public:
	MAPPER122(NES* parent);

	void Reset();
	void WriteLow(WORD address, BYTE data);

protected:
};