#pragma once

#include "bus.h"
#include <cstdint>
#include <vector>

class CPU
{

public:


	CPU();
	~CPU();

	// LOOKUP TABLES
	typedef void (CPU::*addrPtr)(); // typedef for function pointer to the addressing mode function
	typedef void (CPU::*opPtr)();   // typedef for function pointer to the opcode functions
	std::vector<addrPtr> addrPtrs;
	std::vector<opPtr> opPtrs;

	// BUS LOGIC
	Bus* bus;
	void connectBus(Bus* bus) { bus = bus; }
	void write(uint16_t addr, uint8_t val);
	uint8_t read(uint16_t addr);

	// CONTROL REGISTERS
	uint16_t pc = 0x00;	// Program counter
	uint8_t sp = 0x00;	// stack pointer, 256 depth
	uint8_t a = 0x00;	// accumulator
	uint8_t x = 0x00;	// x register
	uint8_t y = 0x00;       // y register


	// CONTROL LOGIC
	void step(); // exectues an instruction
	uint8_t opcode; // opcode for current instruction
	uint8_t cycles; // number of cycles current instruction takes


		
	void push(uint8_t val); // push onto the stack
	uint8_t pop(); // pop from the stack

	uint8_t fetchedVal; // fetched val from mem using addrModes
	uint16_t currAddr; // the current Address, determined from addrMode

	void reset();
	// Logic to determind and check if a page was crossed
 	void isPageCrossed(uint16_t addr, uint16_t hiByte);
	bool pageCrossed = false;

	// Status Flags 
	std::array<bool,8> statusFlags; 
	void setStatus(uint8_t status, bool val) {statusFlags[status] = val;}
	void setStatusZN(bool zeroCond, bool negCond){statusFlags[Z] = zeroCond; statusFlags[N] = negCond;} // since ZN set together a lot
	bool getStatus(uint8_t status) {return statusFlags[status];}
	uint8_t statusToByte(std::array<bool,8> flags);
	void byteToStatus(uint8_t stackByte);
	
	enum flags
	{
		C, // carry
		Z, // zero
		I, // interrupt disable
		D, // decmial mode, not used in emulation
		B, // Break 
		U, // not used
		V, // overflow
		N  // negative
	};

	// Enum for addressing modes, used to set curr addrMode
	enum AddressingMode
	{
		IMP,
		ACC,
		IMM,
		ZP,
		ZPX,
		ZPY,
		REL,
		ABS,
		ABSX,
		ABSY,
		IND,
		INDX,
		INDY
	};
	AddressingMode currAddrMode;

	// struct to represent an opcode and an addressing mode
	struct Instruction
	{
		uint8_t (CPU::*addrMode)(); 
		uint8_t (CPU::*opcode)(); 
	};

	// jumptable for the 256 instructions
	Instruction jmpTable[256];
private:

	//Addressing Modes
	void Implied();	
	void Accumulator();	
	void Immediate();	
	void ZeroPage();	
	void ZeroPageX();	
	void ZeroPageY();	
	void Relative();	
	void Absolute();	
	void AbsoluteX();	
	void AbsoluteY();	
	void Indirect();	
	void IndirectX();	
	void IndirectY();	
	void XXXAddr();

	// 56 opcodes
	void ADC();
	void AND();
	void ASL();
	void BCC();
    	void BCS();
	void BEQ();
	void BIT();
	void BMI();
	void BNE();
	void BPL();
	void BRK();
	void BVC();
	void BVS();
	void CLC();
	void CLD();
	void CLI();
	void CLV();
	void CMP();
	void CPX();
	void CPY();
	void DEC();
	void DEX();
	void DEY();
	void EOR();
	void INC();
	void INX();
	void INY();
	void JMP();
	void JSR();
	void LDA();
	void LDX();
	void LDY();
	void LSR();
	void NOP();
	void ORA();
	void PHA();
	void PHP();
	void PLA();
	void PLP();
	void ROL();
	void ROR();
	void RTI();
	void RTS();
	void SBC();
	void SEC();
	void SED();
	void SEI();
	void STA();
	void STX();
	void STY();
	void TAX();
	void TAY();
	void TSX();
	void TXA();
	void TXS();
	void TYA();
	void XXX();
};
