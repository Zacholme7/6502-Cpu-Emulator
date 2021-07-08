#include "headers/bus.h"

Bus::Bus()
{
	ram.fill(0x00);
}

void Bus::write(uint16_t addr, uint8_t data)
{
	ram[addr] = data;
}

uint8_t Bus::read(uint16_t addr)
{
	return ram[addr];
}

