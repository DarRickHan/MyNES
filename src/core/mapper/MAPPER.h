#ifndef __MAPPER_H__
#define __MAPPER_H__

#include "TYPE.h"
#include "MACRO.h"

class NES;

class MAPPER
{
public:
	MAPPER(NES* parent);
	virtual ~MAPPER();

	virtual void Reset() = 0;
	virtual void Write(WORD address, BYTE data);
	virtual void Read(WORD address, BYTE data);
	virtual void ReadLow(WORD address);
	virtual void WriteLow(WORD address, BYTE data);
	virtual BYTE ExRead(WORD address);
	virtual void ExWrite(WORD address, BYTE data);

	// Extension Commands
	enum EXCMDRD
	{
		EXCMDRD_NONE = 0,
		EXCMDRD_DISKACCESS,
	};
	enum EXCMDWR
	{
		EXCMDWR_NONE = 0,
		EXCMDWR_DISKINSERT,
		EXCMDWR_DISKEJECT,
	};

	virtual BYTE ExCmdRead(EXCMDRD cmd);
	virtual void ExCmdWrite(EXCMDWR cmd, BYTE data);

	virtual void HSync(INT scanline);
	virtual void VSync();
	virtual void Clock(INT cycles);

	virtual void PPU_Latch(WORD address);
	virtual void PPU_ChrLatch(WORD address);
	virtual void PPU_ExtLatchX(INT x);
	virtual void PPU_ExtLatch(WORD address, BYTE& chr_l, BYTE& chr_h, BYTE& attr);

	virtual BOOL IsStateSave();
	virtual void SaveState(LPBYTE p);
	virtual void LoadState(LPBYTE p);

protected:
	NES* nes;
};

#endif	// __MAPPER_H__