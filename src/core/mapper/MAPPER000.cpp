// MAPPER000
MAPPER000::MAPPER000(NES* parent)
:MAPPER(parent)
{}

void MAPPER000::Reset()
{
	switch(PROM_16K_SIZE)
	{
		case 2:	// 32K
		{
			SetPROM_32K_Bank(0);
		}
		break;
		case 1:
		default:	// 16K
		{
			SetPROM_16K_Bank(4, 0);
			SetPROM_16K_Bank(6, 0);
		}
		break;
	}

	DWORD crc = nes->rom->GetPROM_CRC();
	if (crc==0x4e7db5af || crc==0x57970078 || crc==0xaf2bbcbc || crc==0x3acd4bf1)
		nes->SetRenderMethod(NES::POST_RENDER);
}