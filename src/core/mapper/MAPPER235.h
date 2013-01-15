class MAPPER235 : public MAPPER
{
public:
	MAPPER235(NES* parent);

	void Reset();
	void Write(WORD address, BYTE data);

protected:
};