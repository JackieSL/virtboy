#pragma once
#include "../usfl_lib/uslf_lib.hpp"
#include "virtboy_static_data.hpp"
#include "Device.h"

struct CartridgeHeader
{
	u8 entry[4];
	u8 logo[48];
	u8 title[16];
	u16 n_licensee_code;
	u8 sgb_flag;
	u8 cartridge_type;
	u8 rom_size;
	u8 ram_size;
	u8 dest_code;
	u8 old_licensee_code;
	u8 mask_rom_version;
	u8 checksum_header;
	u16 checksum_global;
};

class Cartridge : public Device
{
private:
	u8* rom_data;
	u32 rom_size;


public:
	Cartridge();
	Cartridge(std::string path);
	~Cartridge();

	void Load(std::string path);

	u8 Read(u16 addr);
	void Write(u16 addr, u8 val);

	u16 Read16(u16 addr);
	void Write16(u16 addr, u16 val);

	CartridgeHeader GetHeader();
};

