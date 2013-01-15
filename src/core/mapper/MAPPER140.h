class MAPPER140 : public MAPPER
{
public:
	MAPPER140(NES* parent);

	void Reset();
	void WriteLow(WORD address, BYTE data);

protected:
};