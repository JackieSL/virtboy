#pragma once
#include "../usfl_lib/uslf_lib.hpp"

#define ROM_FOLDER "../gameboy-test-roms-v3.2"
#define ROM_FILE "C:\\Users\\stavros\\source\\repos\\virtboy\\gameboy-test-roms-v3.2\\dmg-acid2\\dmg-acid2.gb"
struct Cartridge
{
	u8* raw_bytes;

	void LoadROM()
	{
		std::string path = ROM_FILE;

		std::ifstream rom(path, std::ios::binary);

		assert(!rom);

		rom.seekg(0, std::ios::end);
		std::streampos length = rom.tellg();
		rom.seekg(0, std::ios::beg);
		raw_bytes = new u8[length];


		rom.read((char*) & raw_bytes[0], length);
	}
};

