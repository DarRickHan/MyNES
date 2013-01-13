class MAPPER246 : public MAPPER
{
public:
	MAPPER246(NES* parent);

	void Reset();
	void WriteLow(WORD address, BYTE data);

protected:
};