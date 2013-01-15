class MAPPER202 : public MAPPER
{
public:
	MAPPER202(NES* parent);

	void Reset();
	void ExWrite(WORD address, BYTE data);
	void WriteLow(WORD address, BYTE data);
	void Write(WORD address, BYTE data);

protected:

private:
	void WriteSub(WORD address, BYTE data);
};