#include "Tests.h"


void TestWritingU16DataAsLE(bool& R, int& argc, std::string* data)
{
	Memory mem;
	u16 r = 0xB2A1;
	mem.Write16(0, r);
	if (mem.Read(0) == 0xa1 && mem.Read(1) == 0xb2 && mem.Read16(0) == 0xb2a1)
	{
		R = true;
	}
	else
	{
		R = false;
		AddEntry("Failed to read data correctly", argc, data);
		
	}
}
void TestHELLO(bool& R, int& argc, std::string* data)
{
	R = false;
	AddEntry("Hello", argc, data);
	AddEntry("World", argc, data);
}

void TestBitops(bool& R, int& argc, std::string* data)
{
	R = true;
	using namespace Bitops;
	if (Make16(0xa2, 0xb2) == 0xa2b2)
	{
		AddEntry("Make16... OK", argc, data);

	}
	else
	{
		AddEntry("Make16... Failed", argc, data);
		R = false;
	}

	if (GetHighByte(0xA2B2) == 0xA2)
	{
		AddEntry("Get High Byte... OK", argc, data);

	}
	else
	{
		AddEntry("Get High Byte... Failed", argc, data);
		R = false;
	}

	if (GetLowByte(0xA2B2) == 0xB2)
	{
		AddEntry("Get Low Byte... OK", argc, data);

	}
	else
	{
		AddEntry("Get Low Byte... Failed", argc, data);
		R = false;
	}

	u16 dummy = 0;
	//SetHighByte(dummy, 0xA2);
	SetLowByte(dummy, 0xB2);
	if (dummy == 0xB2 )
	{
		AddEntry("Set Hi/Lo Byte... OK", argc, data);

	}
	else
	{
		AddEntry("Set Hi/Lo Byte... Failed", argc, data);
		R = false;
	}

	if (CheckBit(0b00000100, 3))
	{
		AddEntry("CheckBit... OK", argc, data);

	}
	else
	{
		AddEntry("CheckBit... Failed", argc, data);
		R = false;
	}
}

void TestROMHeader(bool& R, int& argc, std::string* data)
{

	u8 official_logo[0x30] =
	{
		0xCE, 0xED, 0x66, 0x66, 0xCC, 0x0D, 0x00, 0x0B, 0x03, 0x73, 0x00, 0x83, 0x00, 0x0C, 0x00, 0x0D,
		0x00, 0x08, 0x11, 0x1F, 0x88, 0x89, 0x00, 0x0E, 0xDC, 0xCC, 0x6E, 0xE6, 0xDD, 0xDD, 0xD9, 0x99,
		0xBB, 0xBB, 0x67, 0x63, 0x6E, 0x0E, 0xEC, 0xCC, 0xDD, 0xDC, 0x99, 0x9F, 0xBB, 0xB9, 0x33, 0x3E
	};

	Cartridge cart("C:\\Users\\stavros\\source\\repos\\virtboy\\gameboy-test-roms-v3.2\\dmg-acid2\\dmg-acid2.gb");
	CartridgeHeader hdr = cart.GetHeader();



	bool failed = false;
	for (int i = 0; i < 0x30; i++)
	{
		if (official_logo[i] != hdr.logo[i])
		{
			failed = true;
			AddEntry("Logo comparison failed @" + std::to_string(i - 0x104), argc, data);
			R = false;
			break;
		}
	}
	if (!failed)
	{
		R = true;

		if (hdr.entry != 0)
		{
			AddEntry("Reinterpret Cast succeeded", argc, data);
			std::string output = "\n";
			output += "ROM Title: " + std::string((char*)hdr.title) + "\n";
			output += "Cartridge Type: " + CartridgeTypeStrings[hdr.cartridge_type];
			output += "\nROM Size: " + CartRomString[hdr.rom_size] + "\n";
			output += "RAM Size: " + CartRamString[hdr.ram_size] + "\n";
			output += "Destination Code: " + std::to_string(hdr.dest_code) + "\n";
			output += "Manufacturer:" + licensee_codes[hdr.n_licensee_code] + "\n";
			AddEntry(output, argc, data);
			AddEntry("Checking header checksum...", argc, data);
			u16 x = 0;
			for (int i = 0x134; i <= 0x14C; i++)
			{
				x = x - cart.Read(i) - 1;

			}
			u8 res = Bitops::GetLowByte(x);
			if (res == hdr.checksum_header)
			{
				AddEntry("Checksum succeeded!", argc, data);
			}
			else
			{
				AddEntry("Checksum failed!", argc, data);
			}
		}
		else
		{
			AddEntry("Reinterpret Cast failed!", argc, data);
			R = false;
		}
	}
}

void TestEndianness(bool& R, int& argc, std::string* data)
{
	Memory mem;
	mem.Write(0, 0xA1);
	mem.Write(1, 0xB2);
	u16 r = mem.Read16(0); //expected R = 0xB2A1
	if (r == 0xB2A1)
	{
		R = true;
	}
	else if (r == 0xA1B2)
	{
		AddEntry("Endianess is wrong!", argc, data);
		R = false;
	}
	else
	{
		AddEntry("Endianess is wrong!", argc, data);
		R = false;
	}
}

