class MAPPER225 : public MAPPER
{
public:
	MAPPER225(NES* parent);

	void Reset();
	void Write(WORD address, BYTE data);

protected:
};