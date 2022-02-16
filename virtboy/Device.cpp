#include "Device.h"

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
