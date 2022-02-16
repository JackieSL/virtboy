#pragma once
#include "../usfl_lib/uslf_lib.hpp"
#include "../testotron/testotron.hpp"

#include "../virtboy/Memory.h"
#include "../virtboy/Bitops.hpp"
#include "../virtboy/Cartridge.h"

static std::vector<Test> Tests;

static void AddEntry(std::string message, int& argc, std::string* data)
{
	data[argc] = message;
	argc += 1;
}

void InstructionLoadingTest(bool& R, int& argc, std::string* data);

static void InitTestSuite()
{
	Tests.push_back(Test("Instruction Loading", InstructionLoadingTest));
}