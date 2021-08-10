#include "headers/cpu.h"

CPU::CPU()
{
	opPtrs = 
	{
		&CPU::BRK, &CPU::ORA, &CPU::XXX, &CPU::XXX, &CPU::XXX, &CPU::ORA, &CPU::ASL, &CPU::XXX, &CPU::PHP, &CPU::ORA, &CPU::ASL, &CPU::XXX, &CPU::XXX, &CPU::ORA, &CPU::ASL, &CPU::XXX,
		&CPU::BPL, &CPU::ORA, &CPU::XXX, &CPU::XXX, &CPU::XXX, &CPU::ORA, &CPU::ASL, &CPU::XXX, &CPU::CLC, &CPU::ORA, &CPU::XXX, &CPU::XXX, &CPU::XXX, &CPU::ORA, &CPU::ASL, &CPU::XXX,
		&CPU::JSR, &CPU::AND, &CPU::XXX, &CPU::XXX, &CPU::BIT, &CPU::AND, &CPU::ROL, &CPU::XXX, &CPU::PLP, &CPU::AND, &CPU::ROL, &CPU::XXX, &CPU::BIT, &CPU::AND, &CPU::ROL, &CPU::XXX,
		&CPU::BMI, &CPU::AND, &CPU::XXX, &CPU::XXX, &CPU::XXX, &CPU::AND, &CPU::ROL, &CPU::XXX, &CPU::SEC, &CPU::AND, &CPU::XXX, &CPU::XXX, &CPU::XXX, &CPU::AND, &CPU::ROL, &CPU::XXX,
		&CPU::RTI, &CPU::EOR, &CPU::XXX, &CPU::XXX, &CPU::XXX, &CPU::EOR, &CPU::LSR, &CPU::XXX, &CPU::PHA, &CPU::EOR, &CPU::LSR, &CPU::XXX, &CPU::JMP, &CPU::EOR, &CPU::LSR, &CPU::XXX,
		&CPU::BVC, &CPU::EOR, &CPU::XXX, &CPU::XXX, &CPU::XXX, &CPU::EOR, &CPU::LSR, &CPU::XXX, &CPU::CLI, &CPU::EOR, &CPU::XXX, &CPU::XXX, &CPU::XXX, &CPU::EOR, &CPU::LSR, &CPU::XXX,
		&CPU::RTS, &CPU::ADC, &CPU::XXX, &CPU::XXX, &CPU::XXX, &CPU::ADC, &CPU::ROR, &CPU::XXX, &CPU::PLA, &CPU::ADC, &CPU::ROR, &CPU::XXX, &CPU::JMP, &CPU::ADC, &CPU::ROR, &CPU::XXX,
		&CPU::BVS, &CPU::ADC, &CPU::XXX, &CPU::XXX, &CPU::XXX, &CPU::ADC, &CPU::ROR, &CPU::XXX, &CPU::SEI, &CPU::ADC, &CPU::XXX, &CPU::XXX, &CPU::XXX, &CPU::ADC, &CPU::ROR, &CPU::XXX,
		&CPU::XXX, &CPU::STA, &CPU::XXX, &CPU::XXX, &CPU::STY, &CPU::STA, &CPU::STX, &CPU::XXX, &CPU::DEY, &CPU::XXX, &CPU::TXA, &CPU::XXX, &CPU::STY, &CPU::STA, &CPU::STX, &CPU::XXX,
		&CPU::BCC, &CPU::STA, &CPU::XXX, &CPU::XXX, &CPU::STA, &CPU::STA, &CPU::STX, &CPU::XXX, &CPU::TYA, &CPU::STA, &CPU::TXS, &CPU::XXX, &CPU::XXX, &CPU::STA, &CPU::XXX, &CPU::XXX,
		&CPU::LDY, &CPU::LDA, &CPU::LDX, &CPU::XXX, &CPU::LDY, &CPU::LDA, &CPU::LDX, &CPU::XXX, &CPU::TAY, &CPU::LDA, &CPU::TAX, &CPU::XXX, &CPU::LDY, &CPU::LDA, &CPU::LDX, &CPU::XXX,
		&CPU::BCS, &CPU::LDA, &CPU::XXX, &CPU::XXX, &CPU::LDY, &CPU::LDA, &CPU::LDX, &CPU::XXX, &CPU::CLV, &CPU::LDA, &CPU::TSX, &CPU::XXX, &CPU::LDY, &CPU::LDA, &CPU::LDX, &CPU::XXX,
		&CPU::CPY, &CPU::CMP, &CPU::XXX, &CPU::XXX, &CPU::CPY, &CPU::CMP, &CPU::DEC, &CPU::XXX, &CPU::INY, &CPU::CMP, &CPU::DEX, &CPU::XXX, &CPU::CPY, &CPU::CMP, &CPU::DEC, &CPU::XXX,
		&CPU::BNE, &CPU::CMP, &CPU::XXX, &CPU::XXX, &CPU::XXX, &CPU::CMP, &CPU::DEC, &CPU::XXX, &CPU::CLD, &CPU::CMP, &CPU::XXX, &CPU::XXX, &CPU::XXX, &CPU::CMP, &CPU::DEC, &CPU::XXX,
		&CPU::CPX, &CPU::SBC, &CPU::XXX, &CPU::XXX, &CPU::CPX, &CPU::SBC, &CPU::INC, &CPU::XXX, &CPU::INX, &CPU::SBC, &CPU::NOP, &CPU::XXX, &CPU::CPX, &CPU::SBC, &CPU::INC, &CPU::XXX,
		&CPU::BEQ, &CPU::SBC, &CPU::XXX, &CPU::XXX, &CPU::XXX, &CPU::SBC, &CPU::INC, &CPU::XXX, &CPU::SED, &CPU::SBC, &CPU::XXX, &CPU::XXX, &CPU::XXX, &CPU::SBC, &CPU::INC, &CPU::XXX
	};

	addrPtrs  = 
	{
		&CPU::Implied,   &CPU::IndirectX, &CPU::XXXAddr,   &CPU::XXXAddr, &CPU::XXXAddr,   &CPU::ZeroPage,  &CPU::ZeroPage,  &CPU::XXXAddr, &CPU::Implied, &CPU::Immediate, &CPU::Accumulator, &CPU::XXXAddr, &CPU::XXXAddr,   &CPU::Absolute,  &CPU::Absolute,  &CPU::XXXAddr,
		&CPU::Relative,  &CPU::IndirectY, &CPU::XXXAddr,   &CPU::XXXAddr, &CPU::XXXAddr,   &CPU::ZeroPageX, &CPU::ZeroPageX, &CPU::XXXAddr, &CPU::Implied, &CPU::AbsoluteY, &CPU::XXXAddr,     &CPU::XXXAddr, &CPU::XXXAddr,   &CPU::AbsoluteX, &CPU::AbsoluteX, &CPU::XXXAddr,
		&CPU::Absolute,  &CPU::IndirectX, &CPU::XXXAddr,   &CPU::XXXAddr, &CPU::ZeroPage,  &CPU::ZeroPage,  &CPU::ZeroPage,  &CPU::XXXAddr, &CPU::Implied, &CPU::Immediate, &CPU::Accumulator, &CPU::XXXAddr, &CPU::Absolute,  &CPU::Absolute,  &CPU::Absolute,  &CPU::XXXAddr,
		&CPU::Relative,  &CPU::IndirectY, &CPU::XXXAddr,   &CPU::XXXAddr, &CPU::XXXAddr,   &CPU::ZeroPageX, &CPU::ZeroPageX, &CPU::XXXAddr, &CPU::Implied, &CPU::AbsoluteY, &CPU::XXXAddr,     &CPU::XXXAddr, &CPU::XXXAddr,   &CPU::AbsoluteX, &CPU::AbsoluteX, &CPU::XXXAddr,
		&CPU::Implied,   &CPU::IndirectX, &CPU::XXXAddr,   &CPU::XXXAddr, &CPU::XXXAddr,   &CPU::ZeroPage,  &CPU::ZeroPage,  &CPU::XXXAddr, &CPU::Implied, &CPU::Immediate, &CPU::Accumulator, &CPU::XXXAddr, &CPU::Absolute,  &CPU::Absolute,  &CPU::Absolute,  &CPU::XXXAddr,
		&CPU::Relative,  &CPU::IndirectY, &CPU::XXXAddr,   &CPU::XXXAddr, &CPU::XXXAddr,   &CPU::ZeroPageX, &CPU::ZeroPageX, &CPU::XXXAddr, &CPU::Implied, &CPU::AbsoluteY, &CPU::XXXAddr,     &CPU::XXXAddr, &CPU::XXXAddr,   &CPU::AbsoluteX, &CPU::AbsoluteX, &CPU::XXXAddr,
		&CPU::Implied,   &CPU::IndirectX, &CPU::XXXAddr,   &CPU::XXXAddr, &CPU::XXXAddr,   &CPU::ZeroPage,  &CPU::ZeroPage,  &CPU::XXXAddr, &CPU::Implied, &CPU::Immediate, &CPU::Accumulator, &CPU::XXXAddr, &CPU::Indirect,  &CPU::Absolute,  &CPU::Absolute,  &CPU::XXXAddr,
		&CPU::Relative,  &CPU::IndirectY, &CPU::XXXAddr,   &CPU::XXXAddr, &CPU::XXXAddr,   &CPU::ZeroPageX, &CPU::ZeroPageX, &CPU::XXXAddr, &CPU::Implied, &CPU::AbsoluteY, &CPU::XXXAddr,     &CPU::XXXAddr, &CPU::XXXAddr,   &CPU::AbsoluteX, &CPU::AbsoluteX, &CPU::XXXAddr,
		&CPU::XXXAddr,   &CPU::IndirectX, &CPU::XXXAddr,   &CPU::XXXAddr, &CPU::ZeroPage,  &CPU::ZeroPage,  &CPU::ZeroPage,  &CPU::XXXAddr, &CPU::Implied, &CPU::XXXAddr,   &CPU::Implied,     &CPU::XXXAddr, &CPU::Absolute,  &CPU::Absolute,  &CPU::Absolute,  &CPU::XXXAddr,
		&CPU::Relative,  &CPU::IndirectY, &CPU::XXXAddr,   &CPU::XXXAddr, &CPU::ZeroPageX, &CPU::ZeroPageX, &CPU::ZeroPageY, &CPU::XXXAddr, &CPU::Implied, &CPU::AbsoluteY, &CPU::Implied,     &CPU::XXXAddr, &CPU::XXXAddr,   &CPU::AbsoluteX, &CPU::XXXAddr,   &CPU::XXXAddr,
		&CPU::Immediate, &CPU::IndirectX, &CPU::Immediate, &CPU::XXXAddr, &CPU::ZeroPage,  &CPU::ZeroPage,  &CPU::ZeroPage,  &CPU::XXXAddr, &CPU::Implied, &CPU::Immediate, &CPU::Implied,     &CPU::XXXAddr, &CPU::Absolute,  &CPU::Absolute,  &CPU::Absolute,  &CPU::XXXAddr,
		&CPU::Relative,  &CPU::IndirectY, &CPU::XXXAddr,   &CPU::XXXAddr, &CPU::ZeroPageX, &CPU::ZeroPageX, &CPU::ZeroPageY, &CPU::XXXAddr, &CPU::Implied, &CPU::AbsoluteY, &CPU::Implied,     &CPU::XXXAddr, &CPU::AbsoluteX, &CPU::AbsoluteX, &CPU::AbsoluteY, &CPU::XXXAddr,
		&CPU::Immediate, &CPU::IndirectX, &CPU::XXXAddr,   &CPU::XXXAddr, &CPU::ZeroPage,  &CPU::ZeroPage,  &CPU::ZeroPage,  &CPU::XXXAddr, &CPU::Implied, &CPU::Immediate, &CPU::Implied,     &CPU::XXXAddr, &CPU::Absolute,  &CPU::Absolute,  &CPU::Absolute,  &CPU::XXXAddr,
		&CPU::Relative,  &CPU::IndirectY, &CPU::XXXAddr,   &CPU::XXXAddr, &CPU::XXXAddr,   &CPU::ZeroPageX, &CPU::ZeroPageX, &CPU::XXXAddr, &CPU::Implied, &CPU::AbsoluteY, &CPU::XXXAddr,     &CPU::XXXAddr, &CPU::XXXAddr,   &CPU::AbsoluteX, &CPU::AbsoluteX, &CPU::XXXAddr,
		&CPU::Immediate, &CPU::IndirectX, &CPU::XXXAddr,   &CPU::XXXAddr, &CPU::ZeroPage,  &CPU::ZeroPage,  &CPU::ZeroPage,  &CPU::XXXAddr, &CPU::Implied, &CPU::Immediate, &CPU::Implied,     &CPU::XXXAddr, &CPU::Absolute,  &CPU::Absolute,  &CPU::Absolute,  &CPU::XXXAddr,
		&CPU::Relative,  &CPU::IndirectY, &CPU::XXXAddr,   &CPU::XXXAddr, &CPU::XXXAddr,   &CPU::ZeroPageX, &CPU::ZeroPageX, &CPU::XXXAddr, &CPU::Implied, &CPU::AbsoluteY, &CPU::XXXAddr,     &CPU::XXXAddr, &CPU::XXXAddr,   &CPU::AbsoluteX, &CPU::AbsoluteX, &CPU::XXXAddr
	};
}



void CPU::reset()
{
	
	sp = 0xfd;
	a = x = y = 0x00;

}


// BUS
// --------------------------------------
void CPU::write(uint16_t addr, uint8_t val)
{
	(*bus).write(addr, val);
}

uint8_t CPU::read(uint16_t addr)
{
	return (*bus).read(addr);
}
// ---------------------------------------

// Checks if the page has been crossed, allows "cycle" accuracy (not in hardware sense)
void CPU::isPageCrossed(uint16_t addr, uint16_t hiByte)
{
	if((addr & 0xFF00) != (hiByte << 8))
	{
		pageCrossed = true;
	}
	pageCrossed = false;
}


// Preforms the execution cycles, steps one cycle per execution
void CPU::step()
{
	if(cycles == 0)
	{
		pageCrossed = false;
		// get opcode
		// exe addr mode
		// exe opcode
			
	}
	cycles--;
}

// ADDRESSING MODES IMPLEMENTATION
// --------------------------------------
void CPU::Implied()
{
	currAddrMode = IMP;
}

void CPU::Accumulator()
{
	fetchedVal = a;
	currAddrMode = ACC;
}

void CPU::Immediate()
{
	currAddr = pc++;
	fetchedVal = read(currAddr);
	currAddrMode = IMM;
}

void CPU::ZeroPage()
{
	currAddr = read(pc++) & 0x00FF;
	fetchedVal = read(currAddr);
	currAddrMode = ZP;
}

void CPU::ZeroPageX()
{
	currAddr = (read(pc++) + x) & 0x00FF;
	fetchedVal = read(currAddr);
	currAddrMode = ZPX;
}

void CPU::ZeroPageY()
{
	currAddr = (read(pc++) + y) & 0x00FF;
	fetchedVal = read(currAddr);
	currAddrMode = ZPY;
}

void CPU::Relative()
{
	uint16_t offset = read(pc++);
	if (offset > 0x80)
	{
		currAddr = pc + 1 + offset;
	} 
	else
	{
		currAddr = pc + 1 + offset - 0x100;
	}
	currAddrMode = REL;
}

void CPU::Absolute()
{
	uint16_t rightByte = read(pc++);
	uint16_t leftByte = read(pc++);
	currAddr = (leftByte << 8) | rightByte;
	fetchedVal = read(currAddr);
	currAddrMode = ABS;
}

void CPU::AbsoluteX()
{
	uint16_t rightByte = read(pc++);
	uint16_t leftByte = read(pc++);
	currAddr = ((leftByte << 8) | rightByte) + x;
	fetchedVal = read(currAddr);
	isPageCrossed(currAddr, leftByte);
	currAddrMode = ABSX;
}

void CPU::AbsoluteY()
{
	uint16_t rightByte = read(pc++);
	uint16_t leftByte = read(pc++);
	currAddr = ((leftByte << 8) | rightByte) + y;
	fetchedVal = read(currAddr);
	isPageCrossed(currAddr, leftByte);
	currAddrMode = ABSY;
}

void CPU::Indirect()
{
	uint16_t rightByte = read(pc++);
	uint16_t leftByte = read(pc++);
	uint16_t addrPtr = (leftByte << 8) | rightByte;
	currAddr = (read(addrPtr + 1) << 8) | read(addrPtr);
	fetchedVal = read(currAddr);
	currAddrMode = IND;
}

void CPU::IndirectX()
{
	uint16_t rightByte = read((uint16_t)(read(pc) + x) & 0x00FF);
	uint16_t leftByte = read((uint16_t)(read(pc) + x + 1) & 0x00FF);
	pc++;
	currAddr = (leftByte << 8) | rightByte;
	fetchedVal = read(currAddr);
	currAddrMode = INDX;

}

void CPU::IndirectY()
{
	uint16_t rightByte = read((uint16_t)(read(pc) & 0x00FF));
	uint16_t leftByte = read((uint16_t)(read(pc+1) & 0x00FF));
	pc++;
	currAddr = ((leftByte << 8) | rightByte) + y;
	fetchedVal = read(currAddr);
	isPageCrossed(currAddr, leftByte);
	currAddrMode = INDY;
}
	
//-----------------------------------------




//OPCODE IMPLEMENTATIONS
//-----------------------------------------
void CPU::ADC()
{
	switch(currAddrMode)
	{
		case IMM: cycles += 2; break;
		case ZP: cycles += 3; break;
		case ZPX: cycles += 4; break;
		case ABS: cycles += 4; break;
		case ABSX: {
			if(pageCrossed) cycles +=1;
			cycles += 4;
			break;
		} 
		case ABSY: {
			if(pageCrossed) cycles +=1;
			cycles += 4;
			break;
		} 
		case INDX: cycles += 6; break;
		case INDY: {
			if(pageCrossed) cycles +=1;
			cycles += 5;
			break;
		} 
		default: break;
	}
};

// Logic AND
void CPU::AND()
{
	a &= fetchedVal;
	setStatusZN(a == 0, a & 0x80);
	switch(currAddrMode)
	{
		case IMM: cycles += 2; break;
		case ZP: cycles += 3; break;
		case ZPX: cycles += 4; break;
		case ABS: cycles += 4; break;
		case ABSX: {
			if(pageCrossed) cycles +=1;
			cycles += 4;
			break;
		} 
		case ABSY: {
			if(pageCrossed) cycles +=1;
			cycles += 4;
			break;
		} 
		case INDX: cycles += 6; break;
		case INDY: {
			if(pageCrossed) cycles +=1;
			cycles += 5;
			break;
		} 
		default: break;
	}
}

// Arithmetic shift left
void CPU::ASL()
{
	switch(currAddrMode)
	{
		case ACC: cycles += 2; break;
		case ZP: cycles += 5; break;
		case ZPX: cycles += 6; break;
		case ABS: cycles += 6; break;
		case ABSX: cycles += 7; break;
		default: break;
	}
}

// Branch if Carry Clear
void CPU::BCC()
{
	if(!getStatus(C))
	{
		pc = currAddr;
		cycles += pageCrossed ? 2: 1;
	}
	cycles += 2; 
}

// Branch if Carry Set
void CPU::BCS()
{
	if(getStatus(C))
	{
		pc = currAddr;
		cycles += pageCrossed ? 2: 1;
	}
	cycles += 2; 
}

// Branch if Equal
void CPU::BEQ()
{
	if(getStatus(Z))
	{
		pc = currAddr;
		cycles += pageCrossed ? 2: 1;
	}
	cycles += 2; 
}

// Bit Test
void CPU::BIT()
{
	switch(currAddrMode)
	{
		case ZP: cycles += 3; break;
		case ABS: cycles += 4; break;
		default: break;
	}
}

// Branch if Minus
void CPU::BMI()
{
	if(getStatus(N))
	{
		pc = currAddr;
		cycles += pageCrossed ? 2: 1;
	}
	cycles += 2; 
}

// Branch if not Equal
void CPU::BNE()
{
	if(!getStatus(Z))
	{
		pc = currAddr;
		cycles += pageCrossed ? 2: 1;
	}
	cycles += 2; 
}

// Branch if Positive
void CPU::BPL()
{
	if(!getStatus(N))
	{
		pc = currAddr;
		cycles += pageCrossed ? 2: 1;
	}
	cycles += 2; 
}

// Force Interrupt
void CPU::BRK()
{
	cycles += 7; // implied 
}

// Branch if overflow clear
void CPU::BVC()
{
	if(!getStatus(V))
	{
		pc = currAddr;
		cycles += pageCrossed ? 2: 1;
	}
	cycles += 2; 
}

// Branch if Overflow set
void CPU::BVS()
{
	if(getStatus(V))
	{
		pc = currAddr;
		cycles += pageCrossed ? 2: 1;
	}
	cycles += 2; 
}

// Clear Carry Flag
void CPU::CLC()
{
	setStatus(C, 0);
	cycles += 2;
}

// Clear Decmial Mode
void CPU::CLD()
{
	setStatus(D, 0);
	cycles += 2;
}

// Clear Interrupt Disable
void CPU::CLI()
{
	setStatus(I, 0);
	cycles += 2;
}

// Clear OverFlow Flag
void CPU::CLV()
{
	setStatus(V, 0);
	cycles += 2;
}

void CPU::CMP()
{
	switch(currAddrMode)
	{
		case IMM: cycles += 2; break;
		case ZP: cycles += 3; break;
		case ZPX: cycles += 4; break;
		case ABS: cycles += 4; break;
		case ABSX: {
			if(pageCrossed) cycles +=1;
			cycles += 4;
			break;
		} 
		case ABSY: {
			if(pageCrossed) cycles +=1;
			cycles += 4;
			break;
		} 
		case INDX: cycles += 6; break;
		case INDY: {
			if(pageCrossed) cycles +=1;
			cycles += 5;
			break;
		} 
		default: break;
	}
}

void CPU::CPX()
{
	switch(currAddrMode)
	{
		case IMM: cycles += 2; break;
		case ZP: cycles += 3; break;
		case ABS: cycles += 4; break;
		default: break;
	}
}

void CPU::CPY()
{
	switch(currAddrMode)
	{
		case IMM: cycles += 2; break;
		case ZP: cycles += 3; break;
		case ABS: cycles += 4; break;
		default: break;
	}
}

void CPU::DEC()
{
	switch(currAddrMode)
	{
		case ZP: cycles += 5; break;
		case ZPX: cycles += 6; break;
		case ABS: cycles += 6; break;
		case ABSX: cycles += 7; break;
		default: break;
	}
}

// Decrement X Register
void CPU::DEX()
{
	x -= 1;
	setStatusZN(x == 0x00, x & 0x80);
	cycles += 2; // implied
}

// Decrement Y Register
void CPU::DEY()
{
	y -= 1;
	setStatusZN(y == 0x00, y & 0x80);
	cycles += 2; // implied
}

// Exclusive OR
void CPU::EOR()
{
	a ^= fetchedVal;
	setStatusZN(a == 0x00, a & 0x80);
	switch(currAddrMode)
	{
		case IMM: cycles += 2; break;
		case ZP: cycles += 3; break;
		case ZPX: cycles += 4; break;
		case ABS: cycles += 4; break;
		case ABSX: {
			if(pageCrossed) cycles +=1;
			cycles += 4;
			break;
		} 
		case ABSY: {
			if(pageCrossed) cycles +=1;
			cycles += 4;
			break;
		} 
		case INDX: cycles += 6; break;
		case INDY: {
			if(pageCrossed) cycles +=1;
			cycles += 5;
			break;
		} 
		default: break;
	}
}

// Incremenet Memory
void CPU::INC()
{
	switch(currAddrMode)
	{
		case ZP: cycles += 5; break;
		case ZPX: cycles += 6; break;
		case ABS: cycles += 6; break;
		case ABSX: cycles += 7; break;
		default: break;
	}
}

// Incremenet X Register
void CPU::INX()
{
	x += 1;
	setStatusZN(x == 0x00, x & 0x80);
	cycles += 2; // implied
}

// Incremenet Y Register
void CPU::INY()
{
	y += 1;
	setStatusZN(y == 0x00, y & 0x80);
	cycles += 2; // implied
}

void CPU::JMP()
{
	switch(currAddrMode)
	{
		case ABS: cycles += 3; break;
		case IND: cycles += 5; break;
		default: break;
	}
}

void CPU::JSR()
{
	cycles += 6; // absolute
}

// Load Accumulator
void CPU::LDA()
{
	a = fetchedVal;
	setStatusZN(a == 0x00, a & 0x80);
	switch(currAddrMode)
	{
		case IMM: cycles += 2; break;
		case ZP: cycles += 3; break;
		case ZPX: cycles += 4; break;
		case ABS: cycles += 4; break;
		case ABSX: {
			if(pageCrossed) cycles +=1;
			cycles += 4;
			break;
		} 
		case ABSY: {
			if(pageCrossed) cycles +=1;
			cycles += 4;
			break;
		} 
		case INDX: cycles += 6; break;
		case INDY: {
			if(pageCrossed) cycles +=1;
			cycles += 5;
			break;
		} 
		default: break;
	}

}

// Load X Register
void CPU::LDX()
{
	x = fetchedVal;
	setStatusZN(x == 0x00, x & 0x80);
	switch(currAddrMode)
	{
		case IMM: cycles += 2; break;
		case ZP: cycles += 3; break;
		case ZPY: cycles += 4; break;
		case ABS: cycles += 4; break;
		case ABSY: {
			if(pageCrossed) cycles +=1;
			cycles += 4;
			break;
		}
		default: break;
	}
}

// Load Y Register 
void CPU::LDY()
{
	y = fetchedVal;
	setStatusZN(y == 0x00, y & 0x80);
	switch(currAddrMode)
	{
		case IMM: cycles += 2; break;
		case ZP: cycles += 3; break;
		case ZPX: cycles += 4; break;
		case ABS: cycles += 4; break;
		case ABSX: {
			if(pageCrossed) cycles +=1;
			cycles += 4;
			break;
		}
		default: break;
	}
}

void CPU::LSR()
{
	switch(currAddrMode)
	{
		case ACC: cycles += 2; break;
		case ZP: cycles += 5; break;
		case ZPX: cycles += 6; break;
		case ABS: cycles += 6; break;
		case ABSX: cycles += 7; break;
		default: break;
	}
	
}

void CPU::NOP()
{
	cycles += 2; // implied
}

void CPU::ORA()
{
	a != read(/* some addr */);
	switch(currAddrMode)
	{
		case IMM: cycles += 2; break;
		case ZP: cycles += 3; break;
		case ZPX: cycles += 4; break;
		case ABS: cycles += 4; break;
		case ABSX: {
			if(pageCrossed) cycles +=1;
			cycles += 4;
			break;
		} 
		case ABSY: {
			if(pageCrossed) cycles +=1;
			cycles += 4;
			break;
		} 
		case INDX: cycles += 6; break;
		case INDY: {
			if(pageCrossed) cycles +=1;
			cycles += 5;
			break;
		} 
		default: break;
	}
}

// Push Accumulator
void CPU::PHA()
{
	write(0x0100 + sp, a);
	sp--;
	cycles += 3; // implied
}

// Push Processor status
void CPU::PHP()
{
	write(0x0100 + sp, statusToByte(statusFlags));
	sp--;
	cycles += 3; // implied
}

// Pull Accumulator
void CPU::PLA()
{
	sp++;
	a = read(0x0100 + sp);
	setStatusZN(a == 0x00, a & 0x80);
	cycles += 4; // implied
}

// Pull Processor Status
void CPU::PLP()
{
	sp++;
	byteToStatus(read(0x0100 + sp));
	cycles += 4; // implied
}

// Rotate Left
void CPU::ROL()
{
	uint8_t tmp = (fetchedVal << 1) | getStatus(C);
	setStatus(C, fetchedVal & 0x80);
	setStatusZN(tmp == 0x00, tmp & 0x80);

	if(currAddrMode == ACC)
	{
		a = tmp;
	}
	else
	{
		write(currAddr, tmp);
	}

	switch(currAddrMode)
	{
		case ACC: cycles += 2; break;
		case ZP: cycles += 5; break;
		case ZPX: cycles += 6; break;
		case ABS: cycles += 6; break;
		case ABSX: cycles += 7; break;
		default: break;
	}
}

// Rotate Right
void CPU::ROR()
{
	uint8_t tmp = (getStatus(C) << 7) | (fetchedVal >> 1);
	setStatus(C, fetchedVal & 0x01);
	setStatusZN(tmp == 0x00, tmp & 0x80);

	if(currAddrMode == ACC)
	{
		a = tmp;
	}
	else
	{
		write(currAddr, tmp);
	}
	
	switch(currAddrMode)
	{
		case ACC: cycles += 2; break;
		case ZP: cycles += 5; break;
		case ZPX: cycles += 6; break;
		case ABS: cycles += 6; break;
		case ABSX: cycles += 7; break;
		default: break;
	}
}

void CPU::RTI()
{
	cycles += 6; // implied
}

void CPU::RTS()
{
	cycles += 6; // implied
}

// Subtract with Carry
void CPU::SBC()
{
	switch(currAddrMode)
	{
		case IMM: cycles += 2; break;
		case ZP: cycles += 3; break;
		case ZPX: cycles += 4; break;
		case ABS: cycles += 4; break;
		case ABSX: {
			if(pageCrossed) cycles +=1;
			cycles += 4;
			break;
		} 
		case ABSY: {
			if(pageCrossed) cycles +=1;
			cycles += 4;
			break;
		} 
		case INDX: cycles += 6; break;
		case INDY: {
			if(pageCrossed) cycles +=1;
			cycles += 5;
			break;
		} 
		default: break;
	}
}

// Set Carry Flag
void CPU::SEC()
{
	setStatus(C, 1);
	cycles += 2;
}

// Set Decmimal Flag
void CPU::SED()
{
	setStatus(D, 1);
	cycles += 2;
}

// Set Interrupt Disable
void CPU::SEI()
{
	setStatus(I, 1);
	cycles += 2;
}

// Store Accumulator in Memory
void CPU::STA()
{
	write(currAddr, a);
	switch(currAddrMode)
	{
		case ZP: cycles += 3; break;
		case ZPX: cycles += 4; break;
		case ABS: cycles += 4; break;
		case ABSX: cycles += 5; break;
		case ABSY: cycles += 5; break;
		case INDX: cycles += 6; break;
		case INDY: cycles += 6; break;
		default: break;
	}
	
}

// Store X in Memory
void CPU::STX()
{
	write(currAddr, x);
	switch(currAddrMode)
	{
		case ZP: cycles += 3; break;
		case ZPY: cycles += 4; break;
		case ABS: cycles += 4; break;
		default: break;
	}
}

// Store Y in Memory
void CPU::STY()
{
	write(currAddr, y);
	switch(currAddrMode)
	{
		case ZP: cycles += 3; break;
		case ZPX: cycles += 4; break;
		case ABS: cycles += 4; break;
		default: break;
	}
}

// Transfer Accumulator to X
void CPU::TAX()
{
	x = a;
	setStatusZN(x == 0x00, x & 0x80);
	cycles += 2;
}

// Transfer Accumulator to Y
void CPU::TAY()
{
	y = a;
	setStatusZN(y == 0x00, y & 0x80);
	cycles += 2;
}

// Transfer Stack Pointer to X
void CPU::TSX()
{
	x = sp;
	setStatusZN(x == 0x00, x & 0x80);
	cycles += 2;
}

// Transfer X to Accumulator
void CPU::TXA()
{
	a = x;
	setStatusZN(a == 0x00, a & 0x80);
	cycles += 2;
}

// Transfer X to Stack Pointer
void CPU::TXS()
{
	sp = x;
	cycles += 2;
}

// Transfer Y to Accumulator
void CPU::TYA()
{
	a = y;
	setStatusZN(a == 0x00, a & 0x80);
	cycles += 2;
}
//-----------------------------------------




// HELPERS
//-----------------------------------------
uint8_t CPU::statusToByte(std::array<bool,8> flags)
{
	uint8_t tmp = 0;
	for(int i = 0; i < 8; i++)
	{
		tmp |= (flags[i] << i);
	}
	return tmp;
}


void CPU::byteToStatus(uint8_t stackByte)
{
	for(int i = 0; i < 8; i++)
	{
		setStatus(i, (stackByte >> i) & 1); 
	}
}

//-----------------------------------------

