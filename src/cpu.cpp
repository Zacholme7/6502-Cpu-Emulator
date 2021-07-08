#include "headers/cpu.h"

void CPU::reset()
{
	
	sp = 0xfd;
	a = x = y = 0x00;

	// reset the status flags
	intDis = true;
	carry = zero = decimal = overflow = negative = false;

}



void CPU::clock()
{
	while(cycles > 0)
	{
		
	}
	cycles--;
}


uint8_t CPU::ADC()
{
}

uint8_t CPU::AND()
{
}


uint8_t CPU::ASL()
{
}


uint8_t CPU::BCC()
{
}


uint8_t CPU::BCS()
{
}


uint8_t CPU::BEQ()
{
}


uint8_t CPU::BIT()
{
}

uint8_t CPU::BMI()
{
}

uint8_t CPU::BNE()
{
}

uint8_t CPU::BPL()
{
}

uint8_t CPU::BRK()
{
}

uint8_t CPU::BVC()
{
}

uint8_t CPU::BVS()
{
}

uint8_t CPU::CLC()
{
}

uint8_t CPU::CLD()
{
}

uint8_t CPU::CLI()
{
}

uint8_t CPU::CLV()
{
}

uint8_t CPU::CMP()
{
}

uint8_t CPU::CPX()
{
}
































