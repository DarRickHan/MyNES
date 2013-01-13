class MAPPER244 : public MAPPER
{
public:
	MAPPER244(NES* parent);

	void Reset();
	void Write(WORD address, BYTE data);

protected:
};