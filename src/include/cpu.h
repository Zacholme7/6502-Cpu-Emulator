#ifndef cpu_h
#define cpu_h
#pragma once

#include "bus.h"
#include <cstdint>

class CPU
{

public:
	CPU(Bus &bus); // connect the cpu to the bus

private:
	uint16_t pc;	// Program counter
	uint8_t sp;	// stack pointer
	uint8_t a;	// accumulator
	uint8_t x;	// x register
	uint8_t y;	// y register
};

#endif
