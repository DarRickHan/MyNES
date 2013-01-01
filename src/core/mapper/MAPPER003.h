class MAPPER003 : public MAPPER
{
public:
	MAPPER003(NES* parent);

	void Reset();
	void Write(WORD address, BYTE data);
	
protected:
};