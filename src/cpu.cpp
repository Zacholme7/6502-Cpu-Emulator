#include "headers/cpu.h"

CPU::CPU()
{
	// ADC (Add with Carry)
	jmpTable[0x69] = {&CPU::Immediate, &CPU::ADC};
	jmpTable[0x65] = {&CPU::ZeroPage, &CPU::ADC};
	jmpTable[0x75] = {&CPU::ZeroPageX, &CPU::ADC};
	jmpTable[0x6D] = {&CPU::Absolute, &CPU::ADC};
	jmpTable[0x7D] = {&CPU::AbsoluteX, &CPU::ADC};
	jmpTable[0x79] = {&CPU::AbsoluteY, &CPU::ADC};
	jmpTable[0x61] = {&CPU::IndirectX, &CPU::ADC};
	jmpTable[0x71] = {&CPU::IndirectY, &CPU::ADC};

	// AND (And with Accumulator)
	jmpTable[0x29] = {&CPU::Immediate, &CPU::AND};
	jmpTable[0x25] = {&CPU::ZeroPage, &CPU::AND};
	jmpTable[0x35] = {&CPU::ZeroPageX, &CPU::AND};
	jmpTable[0x2D] = {&CPU::Absolute, &CPU::AND};
	jmpTable[0x3D] = {&CPU::AbsoluteX, &CPU::AND};
	jmpTable[0x39] = {&CPU::AbsoluteY, &CPU::AND};
	jmpTable[0x21] = {&CPU::IndirectX, &CPU::AND};
	jmpTable[0x31] = {&CPU::IndirectY, &CPU::AND};

	// ASL (Arithmetic shift left)
	jmpTable[0x0A] = {&CPU::Accumulator, &CPU::ASL};
	jmpTable[0x06] = {&CPU::ZeroPage, &CPU::ASL};
	jmpTable[0x16] = {&CPU::ZeroPageX, &CPU::ASL};
	jmpTable[0x0E] = {&CPU::Absolute, &CPU::ASL};
	jmpTable[0x1E] = {&CPU::AbsoluteX, &CPU::ASL};

	// BIT (Test Bits)
	jmpTable[0x24] = {&CPU::ZeroPage, &CPU::BIT};
	jmpTable[0x2C] = {&CPU::Absolute, &CPU::BIT};
		
	// Branch Instructions
	jmpTable[0x10] = {&CPU::Relative, &CPU::BPL};
	jmpTable[0x30] = {&CPU::Relative, &CPU::BMI};
	jmpTable[0x50] = {&CPU::Relative, &CPU::BVC};
	jmpTable[0x70] = {&CPU::Relative, &CPU::BVS};
	jmpTable[0x90] = {&CPU::Relative, &CPU::BCC};
	jmpTable[0xB0] = {&CPU::Relative, &CPU::BCS};
	jmpTable[0xD0] = {&CPU::Relative, &CPU::BNE};
	jmpTable[0xF0] = {&CPU::Relative, &CPU::BEQ};

	// BRK (Break)
	jmpTable[0x00] = {&CPU::Implied, &CPU::BEQ};

	// CMP (Compare Accumulator)
	jmpTable[0xC9] = {&CPU::Immediate, &CPU::CMP};
	jmpTable[0xC5] = {&CPU::ZeroPage, &CPU::CMP};
	jmpTable[0xD5] = {&CPU::ZeroPageX, &CPU::CMP};
	jmpTable[0xCD] = {&CPU::Absolute, &CPU::CMP};
	jmpTable[0xDD] = {&CPU::AbsoluteX, &CPU::CMP};
	jmpTable[0xD9] = {&CPU::AbsoluteY, &CPU::CMP};
	jmpTable[0xC1] = {&CPU::IndirectX, &CPU::CMP};
	jmpTable[0xD1] = {&CPU::IndirectY, &CPU::CMP};

	// CPX (Compare X Register)
	jmpTable[0xE0] = {&CPU::Immediate, &CPU::CPX};
	jmpTable[0xE4] = {&CPU::ZeroPage, &CPU::CPX};
	jmpTable[0xEC] = {&CPU::Absolute, &CPU::CPX};

	// CPY (Compare Y Register)
	jmpTable[0xC0] = {&CPU::Immediate, &CPU::CPY};
	jmpTable[0xC4] = {&CPU::ZeroPage, &CPU::CPY};
	jmpTable[0xCC] = {&CPU::Absolute, &CPU::CPY};

	// DEC (Decrement Memory)
	jmpTable[0xC6] = {&CPU::ZeroPage, &CPU::DEC};
	jmpTable[0xD6] = {&CPU::ZeroPageX, &CPU::DEC};
	jmpTable[0xCE] = {&CPU::Absolute, &CPU::DEC};
	jmpTable[0xDE] = {&CPU::AbsoluteX, &CPU::DEC};

	// EOR (Bitwise Exclusive OR)
	jmpTable[0x49] = {&CPU::Immediate, &CPU::EOR};
	jmpTable[0x45] = {&CPU::ZeroPage, &CPU::EOR};
	jmpTable[0x55] = {&CPU::ZeroPageX, &CPU::EOR};
	jmpTable[0x4D] = {&CPU::Absolute, &CPU::EOR};
	jmpTable[0x5D] = {&CPU::AbsoluteX, &CPU::EOR};
	jmpTable[0x59] = {&CPU::AbsoluteY, &CPU::EOR};
	jmpTable[0x41] = {&CPU::IndirectX, &CPU::EOR};
	jmpTable[0x51] = {&CPU::IndirectY, &CPU::EOR};

	// Flag (Processor Status) Instructions
	jmpTable[0x18] = {&CPU::Implied, &CPU::CLC};
	jmpTable[0x38] = {&CPU::Implied, &CPU::SEC};
	jmpTable[0x58] = {&CPU::Implied, &CPU::CLI};
	jmpTable[0x78] = {&CPU::Implied, &CPU::SEI};
	jmpTable[0xB8] = {&CPU::Implied, &CPU::CLV};
	jmpTable[0xD8] = {&CPU::Implied, &CPU::CLD};
	jmpTable[0xF8] = {&CPU::Implied, &CPU::SED};

	// INC (Increment Memory)
	jmpTable[0xE6] = {&CPU::ZeroPage, &CPU::INC};
	jmpTable[0xF6] = {&CPU::ZeroPageX, &CPU::INC};
	jmpTable[0xEE] = {&CPU::Absolute, &CPU::INC};
	jmpTable[0xFE] = {&CPU::AbsoluteX, &CPU::INC};

	// JMP (Jump)
	jmpTable[0x4C] = {&CPU::Absolute, &CPU::JMP};
	jmpTable[0x6C] = {&CPU::Indirect, &CPU::JMP};

	// JSR (Jump to Subroutine)
	jmpTable[0x20] = {&CPU::Absolute, &CPU::JSR};

	// LDA (Load Accumulator)
	jmpTable[0xA9] = {&CPU::Immediate, &CPU::LDA};
	jmpTable[0xA5] = {&CPU::ZeroPage, &CPU::LDA};
	jmpTable[0xB5] = {&CPU::ZeroPageX, &CPU::LDA};
	jmpTable[0xAD] = {&CPU::Absolute, &CPU::LDA};
	jmpTable[0xBD] = {&CPU::AbsoluteX, &CPU::LDA};
	jmpTable[0xB9] = {&CPU::AbsoluteY, &CPU::LDA};
	jmpTable[0xA1] = {&CPU::IndirectX, &CPU::LDA};
	jmpTable[0xB1] = {&CPU::IndirectY, &CPU::LDA};

	// LDX (Load X Register)
	jmpTable[0xA2] = {&CPU::Immediate, &CPU::LDX};
	jmpTable[0xA6] = {&CPU::ZeroPage, &CPU::LDX};
	jmpTable[0xB6] = {&CPU::ZeroPageY, &CPU::LDX};
	jmpTable[0xAE] = {&CPU::Absolute, &CPU::LDX};
	jmpTable[0xBE] = {&CPU::AbsoluteY, &CPU::LDX};
	
	// LDY (Load Y Register)
	jmpTable[0xA0] = {&CPU::Immediate, &CPU::LDY};
	jmpTable[0xA4] = {&CPU::ZeroPage, &CPU::LDY};
	jmpTable[0xB4] = {&CPU::ZeroPageX, &CPU::LDY};
	jmpTable[0xAC] = {&CPU::Absolute, &CPU::LDY};
	jmpTable[0xBC] = {&CPU::AbsoluteX, &CPU::LDY};
	
	// LSR (Logical Shift Right)
	jmpTable[0x4A] = {&CPU::Accumulator, &CPU::LSR};
	jmpTable[0x46] = {&CPU::ZeroPage, &CPU::LSR};
	jmpTable[0x56] = {&CPU::ZeroPageX, &CPU::LSR};
	jmpTable[0x4E] = {&CPU::Absolute, &CPU::LSR};
	jmpTable[0x5E] = {&CPU::AbsoluteX, &CPU::LSR};

	// NOP (No Operation)
	jmpTable[0xEA] = {&CPU::Implied, &CPU::NOP};

	// ORA (Or with Accumulator)
	jmpTable[0x09] = {&CPU::Immediate, &CPU::ORA};
	jmpTable[0x05] = {&CPU::ZeroPage, &CPU::ORA};
	jmpTable[0x15] = {&CPU::ZeroPageX, &CPU::ORA};
	jmpTable[0x0D] = {&CPU::Absolute, &CPU::ORA};
	jmpTable[0x1D] = {&CPU::AbsoluteX, &CPU::ORA};
	jmpTable[0x19] = {&CPU::AbsoluteY, &CPU::ORA};
	jmpTable[0x01] = {&CPU::IndirectX, &CPU::ORA};
	jmpTable[0x11] = {&CPU::IndirectY, &CPU::ORA};

	// Register Instructions
	jmpTable[0xAA] = {&CPU::Implied, &CPU::TAX};
	jmpTable[0x8A] = {&CPU::Implied, &CPU::TXA};
	jmpTable[0xCA] = {&CPU::Implied, &CPU::DEX};
	jmpTable[0xE8] = {&CPU::Implied, &CPU::INX};
	jmpTable[0xA8] = {&CPU::Implied, &CPU::TAY};
	jmpTable[0x98] = {&CPU::Implied, &CPU::TYA};
	jmpTable[0x88] = {&CPU::Implied, &CPU::DEY};
	jmpTable[0xC8] = {&CPU::Implied, &CPU::INY};

	// ROL (Rotate Left)
	jmpTable[0x2A] = {&CPU::Accumulator, &CPU::ROL};
	jmpTable[0x26] = {&CPU::ZeroPage, &CPU::ROL};
	jmpTable[0x36] = {&CPU::ZeroPageX, &CPU::ROL};
	jmpTable[0x2E] = {&CPU::Absolute, &CPU::ROL};
	jmpTable[0x3E] = {&CPU::AbsoluteX, &CPU::ROL};
	
	// ROR (Rotate Right)
	jmpTable[0x6A] = {&CPU::Accumulator, &CPU::ROR};
	jmpTable[0x66] = {&CPU::ZeroPage, &CPU::ROR};
	jmpTable[0x76] = {&CPU::ZeroPageX, &CPU::ROR};
	jmpTable[0x6E] = {&CPU::Absolute, &CPU::ROR};
	jmpTable[0x7E] = {&CPU::AbsoluteX, &CPU::ROR};

	// RTI (Return from Interrupt)
	jmpTable[0x40] = {&CPU::Implied, &CPU::RTI};

	// RTS (Return from Subroutine)	
	jmpTable[0x60] = {&CPU::Implied, &CPU::RTS};
	
	// SBC (Subtract with Carry)
	jmpTable[0xE9] = {&CPU::Immediate, &CPU::SBC};
	jmpTable[0xE5] = {&CPU::ZeroPage, &CPU::SBC};
	jmpTable[0xF5] = {&CPU::ZeroPageX, &CPU::SBC};
	jmpTable[0xED] = {&CPU::Absolute, &CPU::SBC};
	jmpTable[0xFD] = {&CPU::AbsoluteX, &CPU::SBC};
	jmpTable[0xF9] = {&CPU::AbsoluteY, &CPU::SBC};
	jmpTable[0xE1] = {&CPU::IndirectX, &CPU::SBC};
	jmpTable[0xF1] = {&CPU::IndirectY, &CPU::SBC};

	// STA (Store Accumulator)
	jmpTable[0x85] = {&CPU::ZeroPage, &CPU::STA};
	jmpTable[0x95] = {&CPU::ZeroPageX, &CPU::STA};
	jmpTable[0x8D] = {&CPU::Absolute, &CPU::STA};
	jmpTable[0x9D] = {&CPU::AbsoluteX, &CPU::STA};
	jmpTable[0x99] = {&CPU::AbsoluteY, &CPU::STA};
	jmpTable[0x81] = {&CPU::IndirectX, &CPU::STA};
	jmpTable[0x91] = {&CPU::IndirectY, &CPU::STA};
	
	// Stack Instructions	
	jmpTable[0x9A] = {&CPU::Implied, &CPU::TXS};
	jmpTable[0xBA] = {&CPU::Implied, &CPU::TSX};
	jmpTable[0x48] = {&CPU::Implied, &CPU::PHA};
	jmpTable[0x68] = {&CPU::Implied, &CPU::PLA};
	jmpTable[0x08] = {&CPU::Implied, &CPU::PHP};
	jmpTable[0x28] = {&CPU::Implied, &CPU::PLP};

	// STX (Store X Register)
	jmpTable[0x86] = {&CPU::ZeroPage, &CPU::STX};
	jmpTable[0x96] = {&CPU::ZeroPageY, &CPU::STX};
	jmpTable[0x8E] = {&CPU::Absolute, &CPU::STX};
	
	// STY (Store Y Register)
	jmpTable[0x84] = {&CPU::ZeroPage, &CPU::STY};
	jmpTable[0x94] = {&CPU::ZeroPageY, &CPU::STY};
	jmpTable[0x8C] = {&CPU::Absolute, &CPU::STY};
}



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
