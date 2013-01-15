class MAPPER242 : public MAPPER
{
public:
	MAPPER242(NES* parent);

	void Reset();
	void Write(WORD address, BYTE data);

protected:
};