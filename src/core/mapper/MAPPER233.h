class MAPPER233 : public MAPPER
{
public:
	MAPPER233(NES* parent);

	void Reset();
	void Write(WORD address, BYTE data);

protected:
};