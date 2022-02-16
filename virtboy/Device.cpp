#include "Device.h"

Device::Device()
{
    name = "Undefined";
    bound_min = 0;
    bound_max = 0;
}

Device::Device(std::string name, u16 lo, u16 hi)
    : name(name), bound_min(lo), bound_max(hi)
{
}

void Device::SetName(std::string name)
{
    this->name = name;
}

std::string Device::GetName()
{
    return this->name;
}

u16 Device::GetLowBound()
{
    return this->bound_min;
}

u16 Device::GetHighBound()
{
    return this->bound_max;
}
