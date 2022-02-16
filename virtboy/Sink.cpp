#include "Sink.h"

Sink::Sink(std::string name, u16 addr_start, u16 addr_end)
	: Device(name, addr_start, addr_end)
{
	LOG("Initiating Data Sink (" <<name << ") @0x" << std::hex << (u32)addr_start);
	byte = 0;
	word = 0;
}

void Sink::Write(u16 addr, u8 val)
{
	byte = val;
}

void Sink::Write16(u16 addr, u16 val)
{
	word = val;
}

u8 Sink::Read(u16 addr)
{
	return byte;
}

u16 Sink::Read16(u16 addr)
{
	return word;
}
