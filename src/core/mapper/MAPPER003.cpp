// MAPPER003
MAPPER003::MAPPER003(NES* parent)
:MAPPER(parent)
{}

void MAPPER003::Reset()
{
	switch(PROM_16K_SIZE)
	{
		case 1:
		{
			SetPROM_16K_Bank(4, 0);
			SetPROM_16K_Bank(6, 0);
		}
		break;
		case 2:
		{
			SetPROM_32K_Bank(0);
		}
		break;
	}

	DWORD crc = nes->rom->GetPROM_CRC();

	if (crc==0x2b72fe7e)
	{
		nes->SetRenderMethod(NES::TILE_RENDER);
		nes->ppu->SetExtNameTableMode(TRUE);
	}
}

void MAPPER003::Write(WORD address, BYTE data)
{
	SetVROM_8K_Bank(data);
}