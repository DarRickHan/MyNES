class MAPPER151 : public MAPPER
{
public:
	MAPPER151(NES* parent);

	void Reset();
	void Write(WORD address, BYTE data);

protected:
};