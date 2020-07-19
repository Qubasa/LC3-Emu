#pragma once
#include <stdint.h>
#include <bitset>
#include <vector>

typedef std::bitset<16> Instr;

enum { 
    PC_START = 0x3000 
};

// All are 16bit wide
enum Reg {
	R0 = 0,
	R1,
	R2,
	R3,
	R4,
	R5,
	R6,
	R7,
	R_PC, /* program counter */
	R_COND, /* N (negative), Z (zero), and P (positive) */
	R_COUNT, // Num of registers
};

enum class Op
{
    BR = 0, /* branch */
    ADD,    /* add  */
    LD,     /* load */
    ST,     /* store */
    JSR,    /* jump register */
    AND,    /* bitwise and */
    LDR,    /* load register */
    STR,    /* store register */
    LEA,    /* load effective address */
    TRAP,    /* execute trap */
    NOT,    /* bitwise not */
    LDI,    /* load indirect */
    STI,    /* store indirect */
    JMP,    /* jump */
    RES,    /* reserved (unused) */
    RTI,    /* unused */

};

enum class Cond_Flag
{
    POS = 1 << 0, /* P */
    ZRO = 1 << 1, /* Z */
    NEG = 1 << 2, /* N */
};

std::vector<uint16_t> reg(R_COUNT, 0);
std::vector<uint16_t> memory(UINT16_MAX, 0);