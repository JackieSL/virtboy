#include "Bitops.hpp"

u8 Bitops::GetLowByte(u16 value)
{
	return value & 0xFF;
}

void Bitops::SetLowByte(u16& val, u8 nVal)
{
	val &= 0xFF00;
	val |= nVal;
}

u8 Bitops::GetHighByte(u16 value)
{
	return (value & 0xFF00) >> 8;
}

void Bitops::SetHighByte(u16& val, u8 nVal)
{

	val = (nVal << 8) | (val & 0xFF00);
}

u16 Bitops::Make16(u8 hi, u8 lo)
{
	u16 res = (hi << 8) | lo;
	return res;
}
