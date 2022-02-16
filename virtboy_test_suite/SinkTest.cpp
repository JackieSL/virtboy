#include "Tests.h"
#include "../virtboy/Bus.h"
#include "../virtboy/Sink.h"


void DataSinkTest(bool& R, int& argc, std::string* data)
{
	std::string path = "C:\\Users\\stavros\\source\\repos\\virtboy\\gameboy-test-roms-v3.2\\cgb-acid-hell\\cgb-acid-hell.gbc";
	Sink sink("Dummy", 0xFFFE, 0xFFFF);
	Bus bus;
	bus.AttachDevice(&sink);
	AddEntry("Testing u8 loading", argc, data);
	R = true;
	bus.Write(0xFFFE, 'h');
	if (bus.Read(0xFFFE) != 'h')
	{
		R = false;
	}
	bus.Write(0xFFFE, 'e');
	if (bus.Read(0xFFFE) != 'e')
	{
		R = false;
	}
	bus.Write(0xFFFE, 'l');
	if (bus.Read(0xFFFE) != 'l')
	{
		R = false;
	}
	bus.Write(0xFFFE, 'l');
	if (bus.Read(0xFFFE) != 'l')
	{
		R = false;
	}
	bus.Write(0xFFFE, 'o');
	if (bus.Read(0xFFFE) != 'o')
	{
		R = false;
	}

	if(R)
		AddEntry("u8 loading... OK", argc, data);
	else
		AddEntry("u8 loading... Failed.", argc, data);

	AddEntry("Testing u16 loading", argc, data);
	R = true;

	u16 w = 0xA1B2;
	bus.Write16(0xFFFE, w);
	R = (w == bus.Read16(0xFFFE));


	if (R)
		AddEntry("u16 loading... OK", argc, data);
	else
		AddEntry("u16 loading... Failed.", argc, data);
}