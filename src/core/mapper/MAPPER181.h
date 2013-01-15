class MAPPER181 : public MAPPER
{
public:
	MAPPER181(NES* parent);

	void Reset();
	void WriteLow(WORD address, BYTE data);

protected:
};