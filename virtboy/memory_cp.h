#pragma once
#include "../usfl_lib/uslf_lib.hpp"


class Memory
{
private:
	u8* raw;

public:
	Memory();

	~Memory();

	u8 Read(u16 addr);

	void Write(u16 addr, u8 val);

	u16 Read16(u16 first);

	void Write16(u16 first, u16 val);
};

