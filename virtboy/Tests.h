#pragma once
#include "../usfl_lib/uslf_lib.hpp"
#include "../testotron/testotron.hpp"

#include "Memory.h"

static std::vector<Test> Tests;
static void AddEntry(std::string message, int& argc, std::string* data)
{
	data[argc] = message;
	argc += 1;
}

void TestEndianness(bool& R, int& argc, std::string* data);
void TestWritingU16DataAsLE(bool& R, int& argc, std::string* data);
void TestHELLO(bool& R, int& argc, std::string* data);

static void InitTestSuite()
{
	Tests.push_back(Test("Hello World", TestHELLO));
	Tests.push_back(Test("Endianess", TestEndianness));
	Tests.push_back(Test("Writing U16 Data As LE", TestWritingU16DataAsLE));
}