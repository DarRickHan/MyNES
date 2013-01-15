class MAPPER241 : public MAPPER
{
public:
	MAPPER241(NES* parent);

	void Reset();
	void Write(WORD address, BYTE data);

protected:
};