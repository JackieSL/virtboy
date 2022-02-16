#include "Bus.h"

Bus::Bus() : Device("Undefined", 0, 0xFFFF)
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
        bool found = false;
        for (auto d : devices)
        {
            if (IN_RANGE(addr, d->GetLowBound(), d->GetHighBound()))
            {
                found = true;
                val = d->Read(addr);
                break;
            }
        }
        if (!found)
            LOG("Failed to find device @0x"<<std::hex<< addr);
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
    u16 val = 0;
    if (!devices.empty())
    {
        for (auto d : devices)
        {
            if (IN_RANGE(addr, d->GetLowBound(), d->GetHighBound()))
            {
                val = d->Read16(addr);
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
