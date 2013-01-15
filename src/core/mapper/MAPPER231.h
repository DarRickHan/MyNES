class MAPPER231 : public MAPPER
{
public:
	MAPPER231(NES* parent);

	void Reset();
	void Write(WORD address, BYTE data);

protected:
};