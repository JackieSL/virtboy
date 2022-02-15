#include "Clock.h"
#include <chrono>

void Clock::Cycle()
{
	auto t1 = std::chrono::high_resolution_clock::now();
	auto t2 = std::chrono::high_resolution_clock::now();
	while (true)
	{
		t2 = std::chrono::high_resolution_clock::now();
		auto dt = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
		if (dt.count() > this->frequency)
			break;
	}
}
