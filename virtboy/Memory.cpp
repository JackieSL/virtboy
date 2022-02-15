#include "Memory.h"


Memory::Memory()
	: raw(new u8[0xFFFF])
{

}

Memory::~Memory()
{
	delete[] raw;
}

u8 Memory::Read(u16 addr)
{
	return raw[addr % 0xFFFF];
}

void Memory::Write(u16 addr, u8 val)
{
	raw[addr % 0xFFFF] = val;
}

u16 Memory::Read16(u16 first)
{
	u8 byte1 = raw[first];
	u8 byte2 = raw[first + 1];
	u16 result = 0;
	result |= (byte2 << 8) | byte1; // Little Endian
	return result;
}

void Memory::Write16(u16 first, u16 val)
{
	u8 byte1 = (val & 0xFF00) >> 8;
	u8 byte2 = (val & 0xFF);
	raw[first] = byte2;
	raw[first + 1] = byte1;
}