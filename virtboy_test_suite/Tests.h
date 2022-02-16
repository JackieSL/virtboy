#pragma once
#include "../usfl_lib/uslf_lib.hpp"
#include "../testotron/testotron.hpp"

#include "../virtboy/Bitops.hpp"
#include "../virtboy/Cartridge.h"
#include "../virtboy/virtboy_static_data.hpp"

static std::vector<Test> Tests;

static void AddEntry(std::string message, int& argc, std::string* data)
{
	data[argc] = message;
	argc += 1;
}

void CartridgeLoadingTest(bool& R, int& argc, std::string* data);
void DataSinkTest(bool& R, int& argc, std::string* data);
static void InitTestSuite()
{
	Tests.push_back(Test("Cartridge Loading", CartridgeLoadingTest));
	Tests.push_back(Test("Data Sink", DataSinkTest));
}