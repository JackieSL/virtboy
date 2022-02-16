#include "Tests.h"
#include "../virtboy/Bus.h"
#include "../virtboy/Cartridge.h"
#include "../virtboy/Processor.h"


void InstructionLoadingTest(bool& R, int& argc, std::string* data)
{
	R = true;
	u8 dummy_program[] =
	{
		0xC3, 0x00, 0x04,	// jump to 0x04
		0x00, 0x00, 0xC3,   // nop -> nop
		0x00, 0x00			// jump to 0x00
	};

}