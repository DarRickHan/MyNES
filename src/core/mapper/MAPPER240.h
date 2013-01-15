class MAPPER240 : public MAPPER
{
public:
	MAPPER240(NES* parent);

	void Reset();
	void WriteLow(WORD address, BYTE data);

protected:
};