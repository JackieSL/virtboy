#include "Processor.h"

Processor::Processor()
{
}

Processor::~Processor()
{
}

void Processor::Fetch()
{
    NOT_IMPLEMENTED
}

void Processor::Write(u16 addr, u8 val)
{
    bus->Write(addr, val);
}

u8 Processor::Read(u16 addr)
{
    return bus->Read(addr);
}

void Processor::Write16(u16 addr, u16 val)
{
    bus->Write16(addr, val);
}

u16 Processor::Read16(u16 addr)
{
    return bus->Read16(addr);
}
