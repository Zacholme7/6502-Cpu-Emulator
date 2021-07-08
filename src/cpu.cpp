#include "headers/cpu.h"

void CPU::reset()
{
	
	sp = 0xfd;
	a = x = y = 0x00;

}



void CPU::clock()
{
	while(cycles > 0)
	{
		
	}
	cycles--;
}

// ADDRESSING MODES IMPLEMENTATION
// --------------------------------------

uint8_t CPU::IMP()
{
}

uint8_t CPU::IMM()
{
}

uint8_t CPU::ZP0()
{
}

uint8_t CPU::ZPX()
{
}

uint8_t CPU::ZPY()
{
}

uint8_t CPU::REL()
{
}

uint8_t CPU::ABS()
{
}

uint8_t CPU::ABX()
{
}

uint8_t CPU::ABY()
{
}

uint8_t CPU::IND()
{
}

uint8_t CPU::IZX()
{
}

uint8_t CPU::IZY()
{
}
//-----------------------------------------




//OPCODE IMPLEMENTATIONS
//-----------------------------------------
uint8_t CPU::ADC()
{
}

uint8_t CPU::AND()
{
	a &= read(/* some addr */);
	setStatus(Z, a == 0);
	setStatus(N, a & 0x80);
	return 0;
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
	setStatus(C, 0);
	return 0;
}

uint8_t CPU::CLD()
{
	setStatus(D, 0);
	return 0;
}

uint8_t CPU::CLI()
{
	setStatus(I, 0);
	return 0;
}

uint8_t CPU::CLV()
{
	setStatus(V, 0);
	return 0;
}

uint8_t CPU::CMP()
{
	
}

uint8_t CPU::CPX()
{
}

uint8_t CPU::CPY()
{
}

uint8_t CPU::DEC()
{
}

uint8_t CPU::DEX()
{
	x -= 1;
	setStatus(Z, x == 0);
	setStatus(N, x & 0x80);
	return 0;
}

uint8_t CPU::DEY()
{
	y -= 1;
	setStatus(Z, y == 0);
	setStatus(N, y & 0x80);
	return 0;
}

uint8_t CPU::EOR()
{
	a ^= read(/* some addr */);
	setStatus(Z, a == 0);
	setStatus(N, a & 0x80);
	return 0;
}

uint8_t CPU::INC()
{
}

uint8_t CPU::INX()
{
	x += 1;
	setStatus(Z, x == 0);
	setStatus(N, x & 0x80);
	return 0;
}

uint8_t CPU::INY()
{
	y += 1;
	setStatus(Z, y == 0);
	setStatus(N, y & 0x80);
	return 0;
}

uint8_t CPU::JMP()
{
}

uint8_t CPU::JSR()
{
}

uint8_t CPU::LDA()
{
}

uint8_t CPU::LDX()
{
}

uint8_t CPU::LDY()
{
}

uint8_t CPU::LSR()
{
}

uint8_t CPU::NOP()
{
}

uint8_t CPU::ORA()
{
	a != read(/* some addr */);
	return 0;
}

uint8_t CPU::PHA()
{
}

uint8_t CPU::PHP()
{
}

uint8_t CPU::PLA()
{
}

uint8_t CPU::PLP()
{
}

uint8_t CPU::ROL()
{
}

uint8_t CPU::ROR()
{
}

uint8_t CPU::RTI()
{
}

uint8_t CPU::RTS()
{
}

uint8_t CPU::SBC()
{

}

uint8_t CPU::SEC()
{
	setStatus(C, 1);
	return 0;
}

uint8_t CPU::SED()
{
	setStatus(D, 1);
	return 0;
}

uint8_t CPU::SEI()
{
	setStatus(I, 1);
	return 0;
}


uint8_t CPU::STA()
{
	//write(someaddr, a)
	return 0;
}

uint8_t CPU::STX()
{
	//write(someaddr, x)
	return 0;
}

uint8_t CPU::STY()
{
	//write(someaddr, y)
	return 0;
}

uint8_t CPU::TAX()
{
	x = a;
	setStatus(Z, x == 0x00);
	setStatus(N, x & 0x80);
	return 0;
}

uint8_t CPU::TAY()
{
	y = a;
	setStatus(Z, y == 0x00);
	setStatus(N, y & 0x80);
	return 0;
}

uint8_t CPU::TSX()
{
	x = sp;
	setStatus(Z, x == 0x00);
	setStatus(N, x & 0x80);
	return 0;
}

uint8_t CPU::TXA()
{
	a = x;
	setStatus(Z, a == 0x00);
	setStatus(N, a & 0x80);
	return 0;
}

uint8_t CPU::TXS()
{
	sp = x;
	return 0;
}

uint8_t CPU::TYA()
{
	a = y;
	setStatus(Z, a == 0x00);
	setStatus(N, a & 0x80);
	return 0;
}
//-----------------------------------------
