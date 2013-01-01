class MAPPER002 : public MAPPER
{
public:
	MAPPER002(NES* parent);

	void Reset();
	void Write(WORD address, BYTE data);
	void WriteLow(WORD address, BYTE data);

protected:
	BYTE patch;
};