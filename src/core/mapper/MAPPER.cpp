#include "MAPPER.h"

// MAPPER
MAPPER::MAPPER(NES* parent)
:nes(parent)
{}

MAPPER::~MAPPER()
{}

void MAPPER::Write(WORD address, BYTE data)
{}

void MAPPER::Read(WORD address, BYTE data)
{}

BYTE MAPPER::ReadLow(WORD address)
{
	if (address>=0x6000 && address<=0x7FFF)
		return CPU_MEM_BANK[address>>13][address&0x1FFF];

	return (BYTE)(address>>8);
}

void MAPPER::WriteLow(WORD address, BYTE data)
{
	if (address>=0x6000 && address<=0x7FFF)
		CPU_MEM_BANK[address>>13][address&0x1FFF] = data;
}

BYTE MAPPER::ExRead(WORD address)
{
	return 0x00;
}

void MAPPER::ExWrite(WORD address, BYTE data)
{}

BYTE MAPPER::ExCmdRead(EXCMDRD cmd)
{
	return 0x00;
}

void MAPPER::ExCmdWrite(EXCMDWR cmd, BYTE data)
{}

void MAPPER::HSync(INT scanline)
{}

void MAPPER::VSync()
{}

void MAPPER::Clock(INT cycles)
{}

void MAPPER::PPU_Latch(WORD address)
{}

void MAPPER::PPU_ChrLatch(WORD address)
{}

void MAPPER::PPU_ExtLatchX(INT x)
{}

void MAPPER::PPU_ExtLatch(WORD address, BYTE& chr_l, BYTE& chr_h, BYTE& attr)
{}

BOOL MAPPER::IsStateSave()
{
	return FALSE;
}

void MAPPER::SaveState(LPBYTE p)
{}

void MAPPER::LoadState(LPBYTE p)
{}