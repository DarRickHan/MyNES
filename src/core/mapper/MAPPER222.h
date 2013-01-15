class MAPPER222 : public MAPPER
{
public:
	MAPPER222(NES* parent);

	void Reset();
	void Write(WORD address, BYTE data);

protected:
};