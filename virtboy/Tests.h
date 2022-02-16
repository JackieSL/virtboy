#pragma once
#include "../usfl_lib/uslf_lib.hpp"
#include "../testotron/testotron.hpp"

#include "Memory.h"
#include "Bitops.hpp"
#include "Cartridge.h"

static std::vector<Test> Tests;
static void AddEntry(std::string message, int& argc, std::string* data)
{
	data[argc] = message;
	argc += 1;
}

void TestEndianness(bool& R, int& argc, std::string* data);
void TestWritingU16DataAsLE(bool& R, int& argc, std::string* data);
void TestHELLO(bool& R, int& argc, std::string* data);
void TestBitops(bool& R, int& argc, std::string* data);
void TestROMHeader(bool& R, int& argc, std::string* data);

static void InitTestSuite()
{
	Tests.push_back(Test("Hello World", TestHELLO));
	Tests.push_back(Test("Endianess", TestEndianness));
	Tests.push_back(Test("Writing U16 Data As LE", TestWritingU16DataAsLE));
	Tests.push_back(Test("Bit operations", TestBitops));
	Tests.push_back(Test("Rom Header", TestROMHeader));
}