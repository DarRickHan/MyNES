// MAPPER001
MAPPER001::MAPPER001(NES* parent)
:MAPPER(parent)
{}

void MAPPER001::Reset()
{
	reg[0] = 0x0C;
	reg[1] = reg[2] = reg[3] = 0;
	shift = regbuf = 0;
	patch = 0;
	wram_patch = 0;

	if (PROM_16K_SIZE<32)
		SetPROM_32K_Bank(0, 1, PROM_8K_SIZE-2, PROM_8K_SIZE-1);
	else
	{
		SetPROM_16K_Bank(4, 0);
		SetPROM_16K_Bank(6, 16-1);
		patch = 1;
	}

	DWORD crc = nes->rom->GetPROM_CRC();

	switch(crc)
	{
		case 0xb8e16bd0:
		{
			patch = 2;
		}
		break;
		case 0xc96c6f04:
		case 0xd878ebf5:
		case 0x717e1169:
		case 0xC05D2034:
		{
			nes->SetRenderMethod(NES::POST_ALL_RENDER);	
		}
		break;
		case 0x4d2edf70:
		{
			nes->SetRenderMethod(NES::TILE_RENDER);
		}
		break;
		case 0xcd2a73f0:
		{
			nes->SetRenderMethod(NES::TILE_RENDER);
			patch = 2;
		}
		break;
		case 0x466efdc2:
		{
			nes->SetRenderMethod(NES::TILE_RENDER);
			nes->ppu->SetExtMonoMode(TRUE);
		}
		break;
		case 0xc9556b36:
		{
			nes->SetRenderMethod(NES::TILE_RENDER);
			nes->ppu->SetExtMonoMode(TRUE);
			nes->SetSAVERAM_SIZE(16*1024);
			wram_patch = 2;
		}
		break;
		case 0xb8747abf:
		case 0x29449ba9:
		case 0x2b11e0b0:
		case 0x4642dda6:
		case 0xfb69743a:
		case 0x2225c20f:
		case 0xabbf7217:
		{
			nes->SetSAVERAM_SIZE(16*1024);
			wram_patch = 1;
			wram_bank = 0;
			wram_count = 0;
		}
		break;
	}

	
}

void MAPPER001::Write(WORD address, BYTE data)
{
	if (wram_patch==1 && address==0xBFFF)
	{
		wram_count++;
		wram_bank += data&0x01;
		if (wram_count==5)
			SetPROM_Bank(3, &WRAM[0x2000], BANKTYPE_RAM);
		else
			SetPROM_Bank(3, &WRAM[0x0000], BANKTYPE_RAM);
		wram_bank = wram_count = 0;
	}
	
	if (patch!=1)
	{
		if ((address&0x6000)!=(last_address&0x6000))
			shift = regbuf = 0;
		last_address = address;
	}

	if (data & 0x80)
	{
		shift = regbuf = 0;
		reg[0]|=0x0C;
		return;
	}

	if (data&0x01)
		regbuf |= 1<<shift;
	if (++shift<5)
		return;
	address = (address&0x7FFF)>>13;
	reg[address] = regbuf;

	regbuf = shift = 0;

	if (patch!=1)
	{
		switch(address)
		{
			case 0:
			{
				if (reg[0]&0x02)
				{
					if (reg[0]&0x01)
						SetVRAM_Mirror(VRAM_HMIRROR);
					else
						SetVRAM_Mirror(VRAM_VMIRROR);
				}
				else
				{
					if (reg[0]&0x01)
						SetVRAM_Mirror(VRAM_MIRROR4H);
					else
						SetVRAM_Mirror(VRAM_MIRROR4L);
				}
			}
			break;
			case 1:
			{
				if (VROM_1K_SIZE)
				{
					if (reg[0]&0x10)
					{
						SetVROM_4K_Bank(0, reg[1]);
						SetVROM_4K_Bank(4, reg[2]);
					}
					else
						SetVROM_8K_Bank(reg[1]>>1);
				}
				else
				{
					if (reg[0]&0x10)
						SetCRAM_4K_Bank(0, reg[1]);
				}
			}
			break;
			case 2:
			{
				if (VROM_1K_SIZE)
				{
					if (reg[0]&0x10)
					{
						SetVROM_4K_Bank(0, reg[1]);
						SetVROM_4K_Bank(4, reg[2]);
					}
					else
						SetVROM_8K_Bank(reg[1]>>1);
				}
				else
				{
					if (reg[0]&0x10)
						SetCRAM_4K_Bank(4, reg[2]);
				}
			}
			break;
			case 3:
			{
				if (!(reg[0]&0x08))
					SetPROM_32K_Bank(reg[3]>>1);
				else
				{
					if (reg[0]&0x04)
					{
						SetPROM_16K_Bank(4, reg[3]);
						SetPROM_16K_Bank(6, PROM_16K_SIZE);
					}
					else
					{
						SetPROM_16K_Bank(6, reg[3]);
						SetPROM_16K_Bank(4, 0);
					}
				}
			}
			break;
		}
	}
	else
	{
		INT PROM_BASE = 0;
		if (PROM_16K_SIZE>=32)
			PROM_BASE = reg[1]&0x10;

		if (wram_patch==2)
		{
			if (!(reg[1]&0x18))
				SetPROM_Bank(3, &WRAM[0x0000], BANKTYPE_RAM);
			else
				SetPROM_Bank(3, &WRAM[0x2000], BANKTYPE_RAM);
		}

		if (address==0)
		{
			if (reg[0]&0x02)
			{
				if (reg[0]&0x01)
					SetVRAM_Mirror(VRAM_HMIRROR);
				else
					SetVRAM_Mirror(VRAM_VMIRROR);
			}
			else
			{
				if (reg[0]&0x01)
					SetVRAM_Mirror(VRAM_MIRROR4H);
				else
					SetVRAM_Mirror(VRAM_MIRROR4L);
			}
		}

		if (VROM_1K_SIZE)
		{
			if (reg[0]&0x10)
				SetVROM_4K_Bank(0, reg[1]);
			else
				SetVROM_8K_Bank(reg[1]>>1);
		}
		else
		{
			if (reg[0]&0x10)
				SetCRAM_4K_Bank(0, reg[1]);
		}

		if (VROM_1K_SIZE)
		{
			if (reg[0]&0x10)
				SetVROM_4K_Bank(4, reg[2]);
		}
		else
		{
			if (reg[0]&0x10)
				SetCRAM_4K_Bank(4, reg[2]);
		}

		if (!(reg[0]&0x08))
			SetPROM_32K_Bank((reg[3]&(0xF+PROM_BASE))>>1);
		else
		{
			if (reg[0]&0x04)
			{
				SetPROM_16K_Bank(4, PROM_BASE+(reg[3]&0x0F));
				if (PROM_16K_SIZE>=32)
					SetPROM_16K_Bank(6, PROM_BASE+16-1);
			}
			else
			{
				SetPROM_16K_Bank(6, PROM_BASE+(reg[3]&0x0F));
				if (PROM_16K_SIZE>=32)
					SetPROM_16K_Bank(4, PROM_BASE);
			}
		}
	}
}

void MAPPER001::SaveState(LPBYTE p)
{
	p[0] = reg[0];
	p[1] = reg[1];
	p[2] = reg[2];
	p[3] = reg[3];
	p[4] = shift;
	p[5] = regbuf;
	p[6] = wram_bank;
	p[7] = wram_count;
}

void MAPPER001::LoadState(LPBYTE p)
{
	reg[0] = p[0];
	reg[1] = p[1];
	reg[2] = p[2];
	reg[3] = p[3];
	shift = p[4];
	regbuf = p[5];
	wram_bank = p[6];
	wram_count = p[7];
}