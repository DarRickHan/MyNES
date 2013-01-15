class MAPPER180 : public MAPPER
{
public:
	MAPPER180(NES* parent);

	void Reset();
	void Write(WORD address, BYTE data);

protected:
};