// MAPPER002
MAPPER002::MAPPER002(NES* parent)
:MAPPER(parent)
{}

void MAPPER002::Reset()
{}

void MAPPER002::Write(WORD address, BYTE data)
{
	if (patch!=2)
		SetPROM_16K_Bank(4, data);
	else
		SetPROM_16K_Bank(4, data>>4);
}

void MAPPER002::WriteLow(WORD address, BYTE data)
{
	if (!nes->rom->IsSAVERAM())
	{
		if (address>=0x5000 && patch==1)
			SetPROM_16K_Bank(4, data);
	}
	else
		MAPPER::WriteLow(address, data);
}

