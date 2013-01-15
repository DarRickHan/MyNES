class MAPPER185 : public MAPPER
{
public:
	MAPPER185(NES* parent);

	void Reset();
	void Write(WORD address, BYTE data);

protected:
	BYTE patch;
};