#pragma once
#include "../usfl_lib/uslf_lib.hpp"

#include "Bus.h"
#include "Bitops.hpp"

#define FLAG_Z 0b10000000
#define FLAG_N 0b01000000
#define FLAG_H 0b00100000
#define FLAG_C 0b00010000

#define CHECK_BIT(byte, pos) ((byte) & (1 << pos))

class Processor
{
private:
	u16 PC; //Program Counter
	u16 SP; //Stack Pointer
	u16 AF; //Accumulator & Flags
	u16 DE; //u16 Register or u8 D & u8 E
	u16 HL; // ^ same as above

	Bus* bus;

	u16 opcode;
public:
	Processor();
	~Processor();

	void Fetch();



	void Write(u16 addr, u8 val);
	u8 Read(u16 addr);

	void Write16(u16 addr, u16 val);
	u16 Read16(u16 addr);

};

