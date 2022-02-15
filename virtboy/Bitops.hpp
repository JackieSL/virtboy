#pragma once
#include "../usfl_lib/uslf_lib.hpp"

namespace Bitops
{
	u8 GetLowByte(u16 value);

	void SetLowByte(u16& val, u8 nVal);

	u8 GetHighByte(u16 value);

	void SetHighByte(u16& val, u8 nVal);

	u16 Make16(u8 hi, u8 lo);

	bool CheckBit(u8 val, u32 pos);
};




