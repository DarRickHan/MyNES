class MAPPER200 : public MAPPER
{
public:
	MAPPER200(NES* parent);

	void Reset();
	void Write(WORD address, BYTE data);

protected:
};