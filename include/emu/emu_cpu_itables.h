/* @header@ */
#ifndef HAVE_EMU_CPU_ITABLES_H
#define HAVE_EMU_CPU_ITABLES_H

// for i in $(seq 0 255); do printf "\t/* %02x */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},\n" $i; done >> emu_cpu_itables.h */

struct instruction;
struct emu_cpu;

#include "emu/emu_cpu_functions.h"

#define II_SBIT 1
#define II_WBIT 1

#define II_XX_REG1_REG2 1
#define II_MOD_REG_RM 2
#define II_XX_YYY_REG 3
#define II_MOD_YYY_RM 4
#define II_UUUU_TTTN 5
#define II_XX_SREG3_ZZ 6  

#define II_IMM 1
#define II_IMM8 2
#define II_IMM16 3
#define II_IMM32 4

#define II_DISPF 1
#define II_DISP8 2
#define II_DISP16 3
#define II_DISP32 4

/*#define II_LEVEL8 1 -- implementation pending

#define II_TYPE 1 -- impementation pending*/

struct instruction_info
{
	int32_t (*function)(struct emu_cpu *, struct instruction *);
	const char *name;
    
	struct
	{
		uint8_t s_bit : 1;
		uint8_t w_bit : 1;
		uint8_t modrm_byte : 4;
		uint8_t imm_data : 3;
		uint8_t disp_data : 3;
		uint8_t level : 2;
		uint8_t type : 2;
	} format;
};


struct instruction_info ii_onebyte[0x100] = {
	/* 00 */ {instr_add_00, "add", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0}},
	/* 01 */ {instr_add_01, "add", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0}},
	/* 02 */ {instr_add_02, "add", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0}},
	/* 03 */ {instr_add_03, "add", {0, 0, II_MOD_REG_RM, 0, 0, 0, 0}},
	/* 04 */ {instr_add_04, "add", {0, 0, 0, II_IMM8, 0, 0, 0}},
	/* 05 */ {instr_add_05, "add", {0, 0, 0, II_IMM, 0, 0, 0}},
	/* 06 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 07 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 08 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 09 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 0a */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 0b */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 0c */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 0d */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 0e */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 0f */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 10 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 11 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 12 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 13 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 14 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 15 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 16 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 17 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 18 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 19 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 1a */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 1b */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 1c */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 1d */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 1e */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 1f */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 20 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 21 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 22 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 23 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 24 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 25 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 26 */ {prefix_fn, "ES:", {0, 0, 0, 0, 0, 0, 0}},
	/* 27 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 28 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 29 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 2a */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 2b */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 2c */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 2d */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 2e */ {prefix_fn, "CS:", {0, 0, 0, 0, 0, 0, 0}},
	/* 2f */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 30 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 31 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 32 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 33 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 34 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 35 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 36 */ {prefix_fn, "SS:", {0, 0, 0, 0, 0, 0, 0}},
	/* 37 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 38 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 39 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 3a */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 3b */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 3c */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 3d */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 3e */ {prefix_fn, "DS:", {0, 0, 0, 0, 0, 0, 0}},
	/* 3f */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 40 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 41 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 42 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 43 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 44 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 45 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 46 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 47 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 48 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 49 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 4a */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 4b */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 4c */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 4d */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 4e */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 4f */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 50 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 51 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 52 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 53 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 54 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 55 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 56 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 57 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 58 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 59 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 5a */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 5b */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 5c */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 5d */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 5e */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 5f */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 60 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 61 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 62 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 63 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 64 */ {prefix_fn, "FS:", {0, 0, 0, 0, 0, 0, 0}},
	/* 65 */ {prefix_fn, "GS:", {0, 0, 0, 0, 0, 0, 0}},
	/* 66 */ {prefix_fn, "OPSIZE:", {0, 0, 0, 0, 0, 0, 0}},
	/* 67 */ {prefix_fn, "ADSIZE:", {0, 0, 0, 0, 0, 0, 0}},
	/* 68 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 69 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 6a */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 6b */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 6c */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 6d */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 6e */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 6f */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 70 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 71 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 72 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 73 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 74 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 75 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 76 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 77 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 78 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 79 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 7a */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 7b */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 7c */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 7d */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 7e */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 7f */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 80 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 81 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 82 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 83 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 84 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 85 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 86 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 87 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 88 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 89 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 8a */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 8b */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 8c */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 8d */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 8e */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 8f */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 90 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 91 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 92 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 93 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 94 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 95 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 96 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 97 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 98 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 99 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 9a */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 9b */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 9c */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 9d */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 9e */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 9f */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* a0 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* a1 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* a2 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* a3 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* a4 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* a5 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* a6 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* a7 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* a8 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* a9 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* aa */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* ab */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* ac */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* ad */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* ae */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* af */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* b0 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* b1 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* b2 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* b3 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* b4 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* b5 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* b6 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* b7 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* b8 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* b9 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* ba */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* bb */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* bc */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* bd */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* be */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* bf */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* c0 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* c1 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* c2 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* c3 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* c4 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* c5 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* c6 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* c7 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* c8 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* c9 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* ca */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* cb */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* cc */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* cd */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* ce */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* cf */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* d0 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* d1 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* d2 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* d3 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* d4 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* d5 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* d6 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* d7 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* d8 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* d9 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* da */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* db */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* dc */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* dd */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* de */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* df */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* e0 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* e1 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* e2 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* e3 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* e4 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* e5 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* e6 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* e7 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* e8 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* e9 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* ea */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* eb */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* ec */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* ed */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* ee */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* ef */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* f0 */ {prefix_fn, "LOCK:", {0, 0, 0, 0, 0, 0, 0}},
	/* f1 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* f2 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* f3 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* f4 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* f5 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* f6 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* f7 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* f8 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* f9 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* fa */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* fb */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* fc */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* fd */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* fe */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* ff */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
};

struct instruction_info ii_twobyte[0x100] = {
	/* 00 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 01 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 02 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 03 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 04 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 05 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 06 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 07 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 08 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 09 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 0a */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 0b */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 0c */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 0d */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 0e */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 0f */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 10 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 11 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 12 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 13 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 14 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 15 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 16 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 17 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 18 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 19 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 1a */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 1b */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 1c */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 1d */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 1e */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 1f */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 20 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 21 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 22 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 23 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 24 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 25 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 26 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 27 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 28 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 29 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 2a */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 2b */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 2c */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 2d */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 2e */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 2f */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 30 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 31 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 32 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 33 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 34 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 35 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 36 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 37 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 38 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 39 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 3a */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 3b */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 3c */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 3d */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 3e */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 3f */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 40 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 41 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 42 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 43 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 44 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 45 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 46 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 47 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 48 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 49 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 4a */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 4b */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 4c */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 4d */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 4e */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 4f */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 50 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 51 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 52 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 53 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 54 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 55 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 56 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 57 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 58 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 59 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 5a */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 5b */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 5c */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 5d */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 5e */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 5f */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 60 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 61 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 62 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 63 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 64 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 65 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 66 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 67 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 68 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 69 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 6a */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 6b */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 6c */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 6d */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 6e */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 6f */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 70 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 71 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 72 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 73 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 74 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 75 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 76 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 77 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 78 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 79 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 7a */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 7b */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 7c */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 7d */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 7e */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 7f */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 80 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 81 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 82 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 83 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 84 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 85 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 86 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 87 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 88 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 89 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 8a */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 8b */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 8c */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 8d */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 8e */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 8f */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 90 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 91 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 92 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 93 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 94 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 95 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 96 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 97 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 98 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 99 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 9a */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 9b */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 9c */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 9d */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 9e */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* 9f */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* a0 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* a1 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* a2 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* a3 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* a4 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* a5 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* a6 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* a7 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* a8 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* a9 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* aa */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* ab */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* ac */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* ad */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* ae */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* af */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* b0 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* b1 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* b2 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* b3 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* b4 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* b5 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* b6 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* b7 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* b8 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* b9 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* ba */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* bb */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* bc */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* bd */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* be */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* bf */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* c0 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* c1 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* c2 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* c3 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* c4 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* c5 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* c6 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* c7 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* c8 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* c9 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* ca */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* cb */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* cc */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* cd */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* ce */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* cf */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* d0 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* d1 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* d2 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* d3 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* d4 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* d5 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* d6 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* d7 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* d8 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* d9 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* da */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* db */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* dc */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* dd */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* de */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* df */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* e0 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* e1 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* e2 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* e3 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* e4 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* e5 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* e6 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* e7 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* e8 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* e9 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* ea */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* eb */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* ec */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* ed */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* ee */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* ef */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* f0 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* f1 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* f2 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* f3 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* f4 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* f5 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* f6 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* f7 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* f8 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* f9 */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* fa */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* fb */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* fc */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* fd */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* fe */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
	/* ff */ {0, 0, {0, 0, 0, 0, 0, 0, 0}},
};



#endif
