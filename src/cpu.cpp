#include "headers/cpu.h"


CPU::CPU(Bus &bus)
{

}


void CPU::reset()
{
	
	sp = 0xfd;
	a = x = y = 0x00;

	// reset the status flags
	intDis = true;
	carry = zero = decimal = overflow = negative = false;

}






