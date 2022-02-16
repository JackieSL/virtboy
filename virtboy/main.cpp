#include "../usfl_lib/uslf_lib.hpp"
#include "Tests.h"
#include "Cartridge.h"


int main(int argc, char* argv[])
{
	InitTestSuite();
	int counter = 1;

	for (auto T : Tests)
	{
		std::cout << "Running test " << counter << "/" << Tests.size() << ":\n";
		T.Run();
		counter++;
	}

}