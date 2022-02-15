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
		data[argc] = "Failed to read data correctly";
		argc += 1;
	}
}
void TestHELLO(bool& R, int& argc, std::string* data)
{
	R = false;
	data[argc] = "HELLO";
	argc += 1;
	data[argc] = "WORLD!";
	argc += 1;

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
		data[argc] = "Endianess is wrong!";
		argc += 1;
		R = false;
	}
	else
	{
		data[argc] = "Encountered an unexpected value!";
		argc += 1;
		R = false;
	}
}

