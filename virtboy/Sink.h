#pragma once
#include "Device.h"

class Sink : public Device
{
private:
	u8 byte;
	u16 word;
public:
	Sink(std::string name, u16 addr_start, u16 addr_end);

	void Write(u16 addr, u8 val) override;
	void Write16(u16 addr, u16 val) override;

	u8 Read(u16 addr) override;
	u16 Read16(u16 addr) override;
};

