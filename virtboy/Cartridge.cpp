#include "Cartridge.h"

Cartridge::Cartridge()
{
	rom_data = nullptr;
	rom_size = 0;
}

Cartridge::Cartridge(std::string path)
{
	rom_data = nullptr;
	rom_size = 0;
	std::ifstream rom_file(path, std::ios::binary);
	if (!rom_file)
	{
		ERROR("Failed to open " << path);
		return;
	}

	std::stringstream ss;
	ss << rom_file.rdbuf();
	rom_file.close();

	this->rom_size = ss.str().length();
	this->rom_data = new u8[rom_size];
	for (int i = 0; i < rom_size; i++)
	{
		rom_data[i] = (u8)ss.str()[i];
	}
}

Cartridge::~Cartridge()
{
	delete[] rom_data;
}

void Cartridge::Load(std::string path)
{
	std::ifstream rom_file(path, std::ios::binary);
	if (!rom_file)
	{
		ERROR("Failed to open " << path);
		return;
	}

	std::stringstream ss;
	ss << rom_file.rdbuf();
	rom_file.close();

	rom_size = ss.str().length();
	rom_data = new u8[rom_size];
	for (int i = 0; i < rom_size; i++)
	{
		rom_data[i] = (u8)ss.str()[i];
	}
}

u8 Cartridge::Read(u16 addr)
{
	return this->rom_data[addr];
}

void Cartridge::Write(u16 addr, u8 val)
{
	this->rom_data[addr] = val;
}

CartridgeHeader Cartridge::GetHeader()
{
	CartridgeHeader out{};

	if (this->rom_data == nullptr)
	{
		ERROR("ROM data was null");
		return out;
	}
	u8* bytes = new u8[80];
	for (int i = 0; i < 80; i++)
	{
		bytes[i] = this->rom_data[i + 0x100];
	}
	out = *reinterpret_cast<CartridgeHeader*>(bytes);
	return out;
}
