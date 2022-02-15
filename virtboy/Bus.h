#pragma once

#include "../usfl_lib/uslf_lib.hpp"

#include "Processor.h"
#include "Memory.h"


class Bus
{
public:
	Bus()
	{

	}

	~Bus() {}

	void Write(u16 addr, u8 val);
	u8 Read(u16 addr);

	void Write16(u16 addr, u16 val);
	u16 Read16(u16 addr);
};

