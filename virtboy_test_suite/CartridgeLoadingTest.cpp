#include "Tests.h"
#include "../virtboy/Bus.h"
#include "../virtboy/Cartridge.h"



void CartridgeLoadingTest(bool& R, int& argc, std::string* data)
{
	std::string path = "C:\\Users\\stavros\\source\\repos\\virtboy\\gameboy-test-roms-v3.2\\cgb-acid-hell\\cgb-acid-hell.gbc";
	Cartridge cart(path);
	Bus bus;

	bus.AttachDevice(&cart);
	R = true;
	for (int i = 0x104; i < 0x133; i++)
	{
		if (NINTENDO_LOGO[i - 0x104] != bus.Read(i))
		{
			R = false;
			AddEntry("Cartridge failed to load.", argc, data);
			std::stringstream ss;
			ss << "Comparison shattered @0x" << std::hex << i;
			AddEntry(ss.str(), argc, data);
			break;
		}

	}
	if (R)
	{
		AddEntry("Cartridge loaded correctly", argc, data);
	}
	else
	{

	}
}