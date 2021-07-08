#ifndef bus_h
#define bus_h
#pragma once
#include <array>



class Bus
{
public:
	Bus();
	void write(uint16_t addr, uint8_t data);
	uint8_t read(uint16_t addr);
private:
	std::array<uint8_t, 0x800> ram;
};

#endif
