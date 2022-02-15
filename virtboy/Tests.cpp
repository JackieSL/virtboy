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

