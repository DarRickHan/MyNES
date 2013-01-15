class MAPPER201 : public MAPPER
{
public:
	MAPPER201(NES* parent);

	void Reset();
	void Write(WORD address, BYTE data);

protected:
};