#include "Bus.h"

Bus::Bus() : Device(0, 0xFFFF)
{
    State = true;
}

Bus::~Bus()
{
}

void Bus::Write(u16 addr, u8 val)
{
    if (!devices.empty())
    {
        for (auto d : devices)
        {
            if (IN_RANGE(addr, d->GetLowBound(), d->GetHighBound()))
            {
                LOG("Writing " << std::hex << val << " to @0x" << addr << "(" << d->GetName() << ")");
                d->Write(addr, val);
            }
        }
    }
    else
    {
        WARN("No devices have been attached to this bus, Write operation cancelled.");
    }
    return;
}

u8 Bus::Read(u16 addr)
{
    u8 val = 0;
    if (!devices.empty())
    {
        for (auto d : devices)
        {
            if (IN_RANGE(addr, d->GetLowBound(), d->GetHighBound()))
            {
                val = d->Read(addr);
                LOG("Reading " << std::hex << val << " to @0x" << addr << "(" << d->GetName() << ")");
            }
        }
    }
    else
    {
        WARN("No devices have been attached to this bus, Read operation cancelled.");
    }
    return val;
}

void Bus::Write16(u16 addr, u16 val)
{
    if (!devices.empty())
    {
        for (auto d : devices)
        {
            if (IN_RANGE(addr, d->GetLowBound(), d->GetHighBound()))
            {
                LOG("Writing " << std::hex << val << " to @0x" << addr << "(" << d->GetName() << ")");
                d->Write16(addr, val);
            }
        }
    }
    else
    {
        WARN("No devices have been attached to this bus, Write16 operation cancelled.");
    }
    return;
}

u16 Bus::Read16(u16 addr)
{
    u16 val;
    if (!devices.empty())
    {
        for (auto d : devices)
        {
            if (IN_RANGE(addr, d->GetLowBound(), d->GetHighBound()))
            {
                val = d->Read16(addr);
                LOG("Reading " << std::hex << val << " to @0x" << addr << "(" << d->GetName() << ")");
            }
        }
    }
    else
    {
        WARN("No devices have been attached to this bus, Read16 operation cancelled.");
    }
    return val;
}

void Bus::AttachDevice(Device* device)
{
    if (device == nullptr)
    {
        assert("Failed to add device", device != nullptr);
    }
    this->devices.push_back(device);
}
