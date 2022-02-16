#pragma once

#include "../usfl_lib/uslf_lib.hpp"


#include "Cartridge.h"
#include "Device.h"

class Bus : public Device
{
private:
	std::vector<Device*> devices;

	bool State;

public:
	Bus();
	~Bus();


	void Write(u16 addr, u8 val);
	u8 Read(u16 addr);

	void Write16(u16 addr, u16 val);
	u16 Read16(u16 addr);

	void AttachDevice(Device* device);
};

