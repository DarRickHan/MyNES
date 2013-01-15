class MAPPER133 : public MAPPER
{
public:
	MAPPER133(NES* parent);

	void Reset();
	void WriteLow(WORD address, BYTE data);

protected:
};