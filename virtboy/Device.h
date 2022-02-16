#pragma once
#include "../usfl_lib/uslf_lib.hpp"


class Device
{
protected:
	std::string name;
	u16 bound_min, bound_max;
public:
	Device();
	Device(std::string name, u16 lo, u16 hi);

	virtual void Write(u16, u8) = 0;
	virtual u8 Read(u16 addr) = 0;

	virtual void Write16(u16, u16) = 0;
	virtual u16 Read16(u16 addr) = 0;

	void SetName(std::string name);
	std::string GetName();

	u16 GetLowBound();
	u16 GetHighBound();
};

