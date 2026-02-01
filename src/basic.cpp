#include "basic.h"

std::map<int, Instruction> Instruction::table = {
	//
	// 0x00 - 0x0F
	//
	{
		0x00,
		{"NOP", {}, 1}
	},
	{
		0x01,
		{"LD", {{"BC", true}, {"n16", true}}, 3}
	},
	{
		0x02,
		{"LD", {{"BC", false}, {"A", true}}, 1}
	},
	{
		0x03,
		{"INC", {{"BC", true}}, 1}
	},
	{
		0x04,
		{"INC", {{"B", true}}, 1}
	},
	{
		0x05,
		{"DEC", {{"B", true}}, 1}
	},
	{
		0x06,
		{"LD", {{"B", true}, {"n8", true}}, 2}
	},
	{
		0x07,
		{"RLCA", {}, 1}
	},
	{
		0x08,
		{"LD", {{"n16", false}, {"SP", true}}, 3}
	},
	{
		0x09,
		{"ADD", {{"HL", true}, {"BC", true}}, 1}
	},
	{
		0x0A,
		{"LD", {{"A", true}, {"BC", false}}, 1}
	},
	{
		0x0B,
		{"DEC", {{"BC", true}}, 1}
	},
	{
		0x0C,
		{"INC", {{"C", true}}, 1}
	},
	{
		0x0D,
		{"DEC", {{"C", true}}, 1}
	},
	{
		0x0E,
		{"LD", {{"C", true}, {"n8", true}}, 2}
	},
	{
		0x0F,
		{"RRCA", {}, 1}
	},

	//
	// 0x10 - 0x1F
	//
	{
		0x10,
		{"STOP", {{"n8", true}}, 2}
	},
	{
		0x11,
		{"LD", {{"DE", true}, {"n16", true}}, 3}
	},
	{
		0x12,
		{"LD", {{"DE", false}, {"A", true}}, 1}
	},
	{
		0x13,
		{"INC", {{"DE", true}}, 1}
	},
	{
		0x14,
		{"INC", {{"D", true}}, 1}
	},
	{
		0x15,
		{"DEC", {{"D", true}}, 1}
	},
	{
		0x16,
		{"LD", {{"D", true}, {"n8", true}}, 2}
	},
	{
		0x17,
		{"RLA", {}, 1}
	},
	{
		0x18,
		{"JR", {{"n8", true}}, 2}
	},
	{
		0x19,
		{"ADD", {{"HL", true}, {"DE", true}}, 1}
	},
	{
		0x1A,
		{"LD", {{"A", true}, {"DE", false}}, 1}
	},
	{
		0x1B,
		{"DEC", {{"DE", true}}, 1}
	},
	{
		0x1C,
		{"INC", {{"E", true}}, 1}
	},
	{
		0x1D,
		{"DEC", {{"E", true}}, 1}
	},
	{
		0x1E,
		{"LD", {{"E", true}, {"n8", true}}, 2}
	},
	{
		0x1F,
		{"RRA", {}, 1}
	},

	//
	// 0x20 - 0x2F
	//
	{
		0x20,
		{"JR", {{"NZ", true}, {"n8", true}}, 2}
	},
	{
		0x21,
		{"LD", {{"HL", true}, {"n16", true}}, 3}
	},
	{
		0x22,
		{"LD", {{"HL+", false}, {"A", true}}, 1}
	},
	{
		0x23,
		{"INC", {{"HL", true}}, 1}
	},
	{
		0x24,
		{"INC", {{"H", true}}, 1}
	},
	{
		0x25,
		{"DEC", {{"H", true}}, 1}
	},
	{
		0x26,
		{"LD", {{"H", true}, {"n8", true}}, 2}
	},
	{
		0x27,
		{"DAA", {}, 1}
	},
	{
		0x28,
		{"JR", {{"Z", true}, {"n8", true}}, 2}
	},
	{
		0x29,
		{"ADD", {{"HL", true}, {"HL", true}}, 1}
	},
	{
		0x2A,
		{"LD", {{"A", true}, {"HL+", false}}, 1}
	},
	{
		0x2B,
		{"DEC", {{"HL", true}}, 1}
	},
	{
		0x2C,
		{"INC", {{"L", true}}, 1}
	},
	{
		0x2D,
		{"DEC", {{"L", true}}, 1}
	},
	{
		0x2E,
		{"LD", {{"L", true}, {"n8", true}}, 2}
	},
	{
		0x2F,
		{"CPL", {}, 1}
	},

	//
	// 0x30 - 0x3F
	//
	{
		0x30,
		{"JR", {{"NC", true}, {"n8", true}}, 2}
	},
	{
		0x31,
		{"LD", {{"SP", true}, {"n16", true}}, 3}
	},
	{
		0x32,
		{"LD", {{"HL-", false}, {"A", true}}, 1}
	},
	{
		0x33,
		{"INC", {{"SP", true}}, 1}
	},
	{
		0x34,
		{"INC", {{"HL", false}}, 1}
	},
	{
		0x35,
		{"DEC", {{"HL", false}}, 1}
	},
	{
		0x36,
		{"LD", {{"HL", false}, {"n8", true}}, 2}
	},
	{
		0x37,
		{"SCF", {}, 1}
	},
	{
		0x38,
		{"JR", {{"C", true}, {"n8", true}}, 2}
	},
	{
		0x39,
		{"ADD", {{"HL", true}, {"SP", true}}, 1}
	},
	{
		0x3A,
		{"LD", {{"A", true}, {"HL-", false}}, 1}
	},
	{
		0x3B,
		{"DEC", {{"SP", true}}, 1}
	},
	{
		0x3C,
		{"INC", {{"A", true}}, 1}
	},
	{
		0x3D,
		{"DEC", {{"A", true}}, 1}
	},
	{
		0x3E,
		{"LD", {{"A", true}, {"n8", true}}, 2}
	},
	{
		0x3F,
		{"CCF", {}, 1}
	},

	//
	// 0x40 - 0x4F
	//
	{
		0x40,
		{"LD", {{"B", true}, {"B", true}}, 1}
	},
	{
		0x41,
		{"LD", {{"B", true}, {"C", true}}, 1}
	},
	{
		0x42,
		{"LD", {{"B", true}, {"D", true}}, 1}
	},
	{
		0x43,
		{"LD", {{"B", true}, {"E", true}}, 1}
	},
	{
		0x44,
		{"LD", {{"B", true}, {"H", true}}, 1}
	},
	{
		0x45,
		{"LD", {{"B", true}, {"L", true}}, 1}
	},
	{
		0x46,
		{"LD", {{"B", true}, {"HL", false}}, 1}
	},
	{
		0x47,
		{"LD", {{"B", true}, {"A", true}}, 1}
	},
	{
		0x48,
		{"LD", {{"C", true}, {"B", true}}, 1}
	},
	{
		0x49,
		{"LD", {{"C", true}, {"C", true}}, 1}
	},
	{
		0x4A,
		{"LD", {{"C", true}, {"D", true}}, 1}
	},
	{
		0x4B,
		{"LD", {{"C", true}, {"E", true}}, 1}
	},
	{
		0x4C,
		{"LD", {{"C", true}, {"H", true}}, 1}
	},
	{
		0x4D,
		{"LD", {{"C", true}, {"L", true}}, 1}
	},
	{
		0x4E,
		{"LD", {{"C", true}, {"HL", false}}, 1}
	},
	{
		0x4F,
		{"LD", {{"C", true}, {"A", true}}, 1}
	},

	//
	// 0x50 - 0x5F
	//
	{
		0x50,
		{"LD", {{"D", true}, {"B", true}}, 1}
	},
	{
		0x51,
		{"LD", {{"D", true}, {"C", true}}, 1}
	},
	{
		0x52,
		{"LD", {{"D", true}, {"D", true}}, 1}
	},
	{
		0x53,
		{"LD", {{"D", true}, {"E", true}}, 1}
	},
	{
		0x54,
		{"LD", {{"D", true}, {"H", true}}, 1}
	},
	{
		0x55,
		{"LD", {{"D", true}, {"L", true}}, 1}
	},
	{
		0x56,
		{"LD", {{"D", true}, {"HL", false}}, 1}
	},
	{
		0x57,
		{"LD", {{"D", true}, {"A", true}}, 1}
	},
	{
		0x58,
		{"LD", {{"E", true}, {"B", true}}, 1}
	},
	{
		0x59,
		{"LD", {{"E", true}, {"C", true}}, 1}
	},
	{
		0x5A,
		{"LD", {{"E", true}, {"D", true}}, 1}
	},
	{
		0x5B,
		{"LD", {{"E", true}, {"E", true}}, 1}
	},
	{
		0x5C,
		{"LD", {{"E", true}, {"H", true}}, 1}
	},
	{
		0x5D,
		{"LD", {{"E", true}, {"L", true}}, 1}
	},
	{
		0x5E,
		{"LD", {{"E", true}, {"HL", false}}, 1}
	},
	{
		0x5F,
		{"LD", {{"E", true}, {"A", true}}, 1}
	},

	//
	// 0x60 - 0x6F
	//
	{
		0x60,
		{"LD", {{"H", true}, {"B", true}}, 1}
	},
	{
		0x61,
		{"LD", {{"H", true}, {"C", true}}, 1}
	},
	{
		0x62,
		{"LD", {{"H", true}, {"D", true}}, 1}
	},
	{
		0x63,
		{"LD", {{"H", true}, {"E", true}}, 1}
	},
	{
		0x64,
		{"LD", {{"H", true}, {"H", true}}, 1}
	},
	{
		0x65,
		{"LD", {{"H", true}, {"L", true}}, 1}
	},
	{
		0x66,
		{"LD", {{"H", true}, {"HL", false}}, 1}
	},
	{
		0x67,
		{"LD", {{"H", true}, {"A", true}}, 1}
	},
	{
		0x68,
		{"LD", {{"L", true}, {"B", true}}, 1}
	},
	{
		0x69,
		{"LD", {{"L", true}, {"C", true}}, 1}
	},
	{
		0x6A,
		{"LD", {{"L", true}, {"D", true}}, 1}
	},
	{
		0x6B,
		{"LD", {{"L", true}, {"E", true}}, 1}
	},
	{
		0x6C,
		{"LD", {{"L", true}, {"H", true}}, 1}
	},
	{
		0x6D,
		{"LD", {{"L", true}, {"L", true}}, 1}
	},
	{
		0x6E,
		{"LD", {{"L", true}, {"HL", false}}, 1}
	},
	{
		0x6F,
		{"LD", {{"L", true}, {"A", true}}, 1}
	},


	//
	// 0x70 - 0x7F
	//
	{
		0x70,
		{"LD", {{"HL", false}, {"B", true}}, 1}
	},
	{
		0x71,
		{"LD", {{"HL", false}, {"C", true}}, 1}
	},
	{
		0x72,
		{"LD", {{"HL", false}, {"D", true}}, 1}
	},
	{
		0x73,
		{"LD", {{"HL", false}, {"E", true}}, 1}
	},
	{
		0x74,
		{"LD", {{"HL", false}, {"H", true}}, 1}
	},
	{
		0x75,
		{"LD", {{"HL", false}, {"L", true}}, 1}
	},
	{
		0x76,
		{"HALT", {}, 1}
	},
	{
		0x77,
		{"LD", {{"HL", false}, {"A", true}}, 1}
	},
	{
		0x78,
		{"LD", {{"A", true}, {"B", true}}, 1}
	},
	{
		0x79,
		{"LD", {{"A", true}, {"C", true}}, 1}
	},
	{
		0x7A,
		{"LD", {{"A", true}, {"D", true}}, 1}
	},
	{
		0x7B,
		{"LD", {{"A", true}, {"E", true}}, 1}
	},
	{
		0x7C,
		{"LD", {{"A", true}, {"H", true}}, 1}
	},
	{
		0x7D,
		{"LD", {{"A", true}, {"L", true}}, 1}
	},
	{
		0x7E,
		{"LD", {{"A", true}, {"HL", false}}, 1}
	},
	{
		0x7F,
		{"LD", {{"A", true}, {"A", true}}, 1}
	},

	//
	// 0x80 - 0x8F
	//
	{
		0x80,
		{"ADD", {{"A", true}, {"B", true}}, 1}
	},
	{
		0x81,
		{"ADD", {{"A", true}, {"C", true}}, 1}
	},
	{
		0x82,
		{"ADD", {{"A", true}, {"D", true}}, 1}
	},
	{
		0x83,
		{"ADD", {{"A", true}, {"E", true}}, 1}
	},
	{
		0x84,
		{"ADD", {{"A", true}, {"H", true}}, 1}
	},
	{
		0x85,
		{"ADD", {{"A", true}, {"L", true}}, 1}
	},
	{
		0x86,
		{"ADD", {{"A", true}, {"HL", false}}, 1}
	},
	{
		0x87,
		{"ADD", {{"A", true}, {"A", true}}, 1}
	},
	{
		0x88,
		{"ADC", {{"A", true}, {"B", true}}, 1}
	},
	{
		0x89,
		{"ADC", {{"A", true}, {"C", true}}, 1}
	},
	{
		0x8A,
		{"ADC", {{"A", true}, {"D", true}}, 1}
	},
	{
		0x8B,
		{"ADC", {{"A", true}, {"E", true}}, 1}
	},
	{
		0x8C,
		{"ADC", {{"A", true}, {"H", true}}, 1}
	},
	{
		0x8D,
		{"ADC", {{"A", true}, {"L", true}}, 1}
	},
	{
		0x8E,
		{"ADC", {{"A", true}, {"HL", false}}, 1}
	},
	{
		0x8F,
		{"ADC", {{"A", true}, {"A", true}}, 1}
	},

	//
	// 0x90 - 0x9F
	//
	{
		0x90,
		{"SUB", {{"B", true}}, 1}
	},
	{
		0x91,
		{"SUB", {{"C", true}}, 1}
	},
	{
		0x92,
		{"SUB", {{"D", true}}, 1}
	},
	{
		0x93,
		{"SUB", {{"E", true}}, 1}
	},
	{
		0x94,
		{"SUB", {{"H", true}}, 1}
	},
	{
		0x95,
		{"SUB", {{"L", true}}, 1}
	},
	{
		0x96,
		{"SUB", {{"HL", false}}, 1}
	},
	{
		0x97,
		{"SUB", {{"A", true}}, 1}
	},
	{
		0x98,
		{"SBC", {{"A", true}, {"B", true}}, 1}
	},
	{
		0x99,
		{"SBC", {{"A", true}, {"C", true}}, 1}
	},
	{
		0x9A,
		{"SBC", {{"A", true}, {"D", true}}, 1}
	},
	{
		0x9B,
		{"SBC", {{"A", true}, {"E", true}}, 1}
	},
	{
		0x9C,
		{"SBC", {{"A", true}, {"H", true}}, 1}
	},
	{
		0x9D,
		{"SBC", {{"A", true}, {"L", true}}, 1}
	},
	{
		0x9E,
		{"SBC", {{"A", true}, {"HL", false}}, 1}
	},
	{
		0x9F,
		{"SBC", {{"A", true}, {"A", true}}, 1}
	},


	//
	// 0xA0 - 0xAF
	//
	{
		0xA0,
		{"AND", {{"B", true}}, 1}
	},
	{
		0xA1,
		{"AND", {{"C", true}}, 1}
	},
	{
		0xA2,
		{"AND", {{"D", true}}, 1}
	},
	{
		0xA3,
		{"AND", {{"E", true}}, 1}
	},
	{
		0xA4,
		{"AND", {{"H", true}}, 1}
	},
	{
		0xA5,
		{"AND", {{"L", true}}, 1}
	},
	{
		0xA6,
		{"AND", {{"HL", false}}, 1}
	},
	{
		0xA7,
		{"AND", {{"A", true}}, 1}
	},
	{
		0xA8,
		{"XOR", {{"B", true}}, 1}
	},
	{
		0xA9,
		{"XOR", {{"C", true}}, 1}
	},
	{
		0xAA,
		{"XOR", {{"D", true}}, 1}
	},
	{
		0xAB,
		{"XOR", {{"E", true}}, 1}
	},
	{
		0xAC,
		{"XOR", {{"H", true}}, 1}
	},
	{
		0xAD,
		{"XOR", {{"L", true}}, 1}
	},
	{
		0xAE,
		{"XOR", {{"HL", false}}, 1}
	},
	{
		0xAF,
		{"XOR", {{"A", true}}, 1}
	},

	//
	// 0xB0 - 0xBF
	//
	{
		0xB0,
		{"OR", {{"B", true}}, 1}
	},
	{
		0xB1,
		{"OR", {{"C", true}}, 1}
	},
	{
		0xB2,
		{"OR", {{"D", true}}, 1}
	},
	{
		0xB3,
		{"OR", {{"E", true}}, 1}
	},
	{
		0xB4,
		{"OR", {{"H", true}}, 1}
	},
	{
		0xB5,
		{"OR", {{"L", true}}, 1}
	},
	{
		0xB6,
		{"OR", {{"HL", false}}, 1}
	},
	{
		0xB7,
		{"OR", {{"A", true}}, 1}
	},
	{
		0xB8,
		{"CP", {{"B", true}}, 1}
	},
	{
		0xB9,
		{"CP", {{"C", true}}, 1}
	},
	{
		0xBA,
		{"CP", {{"D", true}}, 1}
	},
	{
		0xBB,
		{"CP", {{"E", true}}, 1}
	},
	{
		0xBC,
		{"CP", {{"H", true}}, 1}
	},
	{
		0xBD,
		{"CP", {{"L", true}}, 1}
	},
	{
		0xBE,
		{"CP", {{"HL", false}}, 1}
	},
	{
		0xBF,
		{"CP", {{"A", true}}, 1}
	},

	//
	// 0xC0 - 0xCF
	//
	{
		0xC0,
		{"RET", {{"NZ", true}}, 1}
	},
	{
		0xC1,
		{"POP", {{"BC", true}}, 1}
	},
	{
		0xC2,
		{"JP", {{"NZ", true}, {"n16", true}}, 3}
	},
	{
		0xC3,
		{"JP", {{"n16", true}}, 3}
	},
	{
		0xC4,
		{"CALL", {{"NZ", true}, {"n16", true}}, 3}
	},
	{
		0xC5,
		{"PUSH", {{"BC", true}}, 1}
	},
	{
		0xC6,
		{"ADD", {{"A", true}, {"n8", true}}, 2}
	},
	{
		0xC7,
		{"RST", {{"$00", true}}, 1}
	},
	{
		0xC8,
		{"RET", {{"Z", true}}, 1}
	},
	{
		0xC9,
		{"RET", {}, 1}
	},
	{
		0xCA,
		{"JP", {{"Z", true}, {"n16", true}}, 3}
	},
	{
		0xCC,
		{"CALL", {{"Z", true}, {"n16", true}}, 3}
	},
	{
		0xCD,
		{"CALL", {{"n16", true}}, 3}
	},
	{
		0xCE,
		{"ADC", {{"A", true}, {"n8", true}}, 2}
	},
	{
		0xCF,
		{"RST", {{"$08", true}}, 1}
	},

	//
	// 0xD0 - 0xDF
	//
	{
		0xD0,
		{"RET", {{"NC", true}}, 1}
	},
	{
		0xD1,
		{"POP", {{"DE", true}}, 1}
	},
	{
		0xD2,
		{"JP", {{"NC", true}, {"n16", true}}, 3}
	},
	{
		0xD4,
		{"CALL", {{"NC", true}, {"n16", true}}, 3}
	},
	{
		0xD5,
		{"PUSH", {{"DE", true}}, 1}
	},
	{
		0xD6,
		{"SUB", {{"n8", true}}, 2}
	},
	{
		0xD7,
		{"RST", {{"$10", true}}, 1}
	},
	{
		0xD8,
		{"RET", {{"C", true}}, 1}
	},
	{
		0xD9,
		{"RETI", {}, 1}
	},
	{
		0xDA,
		{"JP", {{"C", true}, {"n16", true}}, 3}
	},
	{
		0xDC,
		{"CALL", {{"C", true}, {"n16", true}}, 3}
	},
	{
		0xDE,
		{"SBC", {{"A", true}, {"n8", true}}, 2}
	},
	{
		0xDF,
		{"RST", {{"$18", true}}, 1}
	},

	//
	// 0xE0 - 0xEF
	//
	{
		0xE0,
		{"LDH", {{"n8", false}, {"A", true}}, 2}
	},
	{
		0xE1,
		{"POP", {{"HL", true}}, 1}
	},
	{
		0xE2,
		{"LDH", {{"C", false}, {"A", true}}, 1}
	},
	{
		0xE5,
		{"PUSH", {{"HL", true}}, 1}
	},
	{
		0xE6,
		{"AND", {{"A", true}, {"n8", true}}, 2}
	},
	{
		0xE7,
		{"RST", {{"$20", true}}, 1}
	},
	{
		0xE8,
		{"ADD", {{"SP", true}, {"n8", true}}, 2}
	},
	{
		0xE9,
		{"JP", {{"HL", true}}, 1}
	},
	{
		0xEA,
		{"LD", {{"n16", false}, {"A", true}}, 3}
	},
	{
		0xEE,
		{"XOR", {{"A", true}, {"n8", true}}, 2}
	},
	{
		0xEF,
		{"RST", {{"$28", true}}, 1}
	},

	//
	// 0xF0 - 0xFA
	//
	{
		0xF0,
		{"LDH", {{"A", true}, {"n8", false}}, 2}
	},
	{
		0xF1,
		{"POP", {{"AF", true}}, 1}
	},
	{
		0xF2,
		{"LDH", {{"A", true}, {"C", false}}, 1}
	},
	{
		0xF3,
		{"DI", {}, 1}
	},
	{
		0xF5,
		{"PUSH", {{"AF", true}}, 1}
	},
	{
		0xF6,
		{"OR", {{"A", true}, {"n8", true}}, 2}
	},
	{
		0xF7,
		{"RST", {{"$30", true}}, 1}
	},
	{
		0xF8,
		{"LDHL", {{"SP", true}, {"n8", true}}, 2}
	},
	{
		0xF9,
		{"LD", {{"SP", true}, {"HL", true}}, 1}
	},
	{
		0xFA,
		{"LD", {{"A", true}, {"n16", false}}, 3}
	},
	{
		0xFB,
		{"EI", {}, 1}
	},
	{
		0xFE,
		{"CP", {{"A", true}, {"n8", true}}, 2}
	},
	{
		0xFF,
		{"RST", {{"$38", true}}, 1}
	},
};

std::map<int, Instruction> Instruction::table_cbpfx = {
	//
	// 0x00 - 0x0F
	//
	{
		0x00,
		{"RLC", {{"B", true}}, 2}
	},
	{
		0x01,
		{"RLC", {{"C", true}}, 2}
	},
	{
		0x02,
		{"RLC", {{"D", true}}, 2}
	},
	{
		0x03,
		{"RLC", {{"E", true}}, 2}
	},
	{
		0x04,
		{"RLC", {{"H", true}}, 2}
	},
	{
		0x05,
		{"RLC", {{"L", true}}, 2}
	},
	{
		0x06,
		{"RLC", {{"HL", false}}, 2}
	},
	{
		0x07,
		{"RLC", {{"A", true}}, 2}
	},
	{
		0x08,
		{"RRC", {{"B", true}}, 2}
	},
	{
		0x09,
		{"RRC", {{"C", true}}, 2}
	},
	{
		0x0A,
		{"RRC", {{"D", true}}, 2}
	},
	{
		0x0B,
		{"RRC", {{"E", true}}, 2}
	},
	{
		0x0C,
		{"RRC", {{"H", true}}, 2}
	},
	{
		0x0D,
		{"RRC", {{"L", true}}, 2}
	},
	{
		0x0E,
		{"RRC", {{"HL", false}}, 2}
	},
	{
		0x0F,
		{"RRC", {{"A", true}}, 2}
	},

	//
	// 0x10 - 0x1F
	//
	{
		0x10,
		{"RL", {{"B", true}}, 2}
	},
	{
		0x11,
		{"RL", {{"C", true}}, 2}
	},
	{
		0x12,
		{"RL", {{"D", true}}, 2}
	},
	{
		0x13,
		{"RL", {{"E", true}}, 2}
	},
	{
		0x14,
		{"RL", {{"H", true}}, 2}
	},
	{
		0x15,
		{"RL", {{"L", true}}, 2}
	},
	{
		0x16,
		{"RL", {{"HL", false}}, 2}
	},
	{
		0x17,
		{"RL", {{"A", true}}, 2}
	},
	{
		0x18,
		{"RR", {{"B", true}}, 2}
	},
	{
		0x19,
		{"RR", {{"C", true}}, 2}
	},
	{
		0x1A,
		{"RR", {{"D", true}}, 2}
	},
	{
		0x1B,
		{"RR", {{"E", true}}, 2}
	},
	{
		0x1C,
		{"RR", {{"H", true}}, 2}
	},
	{
		0x1D,
		{"RR", {{"L", true}}, 2}
	},
	{
		0x1E,
		{"RR", {{"HL", false}}, 2}
	},
	{
		0x1F,
		{"RR", {{"A", true}}, 2}
	},

	//
	// 0x20 - 0x2F
	//
	{
		0x20,
		{"SLA", {{"B", true}}, 2}
	},
	{
		0x21,
		{"SLA", {{"C", true}}, 2}
	},
	{
		0x22,
		{"SLA", {{"D", true}}, 2}
	},
	{
		0x23,
		{"SLA", {{"E", true}}, 2}
	},
	{
		0x24,
		{"SLA", {{"H", true}}, 2}
	},
	{
		0x25,
		{"SLA", {{"L", true}}, 2}
	},
	{
		0x26,
		{"SLA", {{"HL", false}}, 2}
	},
	{
		0x27,
		{"SLA", {{"A", true}}, 2}
	},
	{
		0x28,
		{"SRA", {{"B", true}}, 2}
	},
	{
		0x29,
		{"SRA", {{"C", true}}, 2}
	},
	{
		0x2A,
		{"SRA", {{"D", true}}, 2}
	},
	{
		0x2B,
		{"SRA", {{"E", true}}, 2}
	},
	{
		0x2C,
		{"SRA", {{"H", true}}, 2}
	},
	{
		0x2D,
		{"SRA", {{"L", true}}, 2}
	},
	{
		0x2E,
		{"SRA", {{"HL", false}}, 2}
	},
	{
		0x2F,
		{"SRA", {{"A", true}}, 2}
	},

	//
	// 0x30 - 0x3F
	//
	{
		0x30,
		{"SWAP", {{"B", true}}, 2}
	},
	{
		0x31,
		{"SWAP", {{"C", true}}, 2}
	},
	{
		0x32,
		{"SWAP", {{"D", true}}, 2}
	},
	{
		0x33,
		{"SWAP", {{"E", true}}, 2}
	},
	{
		0x34,
		{"SWAP", {{"H", true}}, 2}
	},
	{
		0x35,
		{"SWAP", {{"L", true}}, 2}
	},
	{
		0x36,
		{"SWAP", {{"HL", false}}, 2}
	},
	{
		0x37,
		{"SWAP", {{"A", true}}, 2}
	},
	{
		0x38,
		{"SRL", {{"B", true}}, 2}
	},
	{
		0x39,
		{"SRL", {{"C", true}}, 2}
	},
	{
		0x3A,
		{"SRL", {{"D", true}}, 2}
	},
	{
		0x3B,
		{"SRL", {{"E", true}}, 2}
	},
	{
		0x3C,
		{"SRL", {{"H", true}}, 2}
	},
	{
		0x3D,
		{"SRL", {{"L", true}}, 2}
	},
	{
		0x3E,
		{"SRL", {{"HL", false}}, 2}
	},
	{
		0x3F,
		{"SRL", {{"A", true}}, 2}
	},

	//
	// 0x40 - 0x4F
	//
	{
		0x40,
		{"BIT", {{"0", true}, {"B", true}}, 2}
	},
	{
		0x41,
		{"BIT", {{"0", true}, {"C", true}}, 2}
	},
	{
		0x42,
		{"BIT", {{"0", true}, {"D", true}}, 2}
	},
	{
		0x43,
		{"BIT", {{"0", true}, {"E", true}}, 2}
	},
	{
		0x44,
		{"BIT", {{"0", true}, {"H", true}}, 2}
	},
	{
		0x45,
		{"BIT", {{"0", true}, {"L", true}}, 2}
	},
	{
		0x46,
		{"BIT", {{"0", true}, {"HL", false}}, 2}
	},
	{
		0x47,
		{"BIT", {{"0", true}, {"A", true}}, 2}
	},
	{
		0x48,
		{"BIT", {{"1", true}, {"B", true}}, 2}
	},
	{
		0x49,
		{"BIT", {{"1", true}, {"C", true}}, 2}
	},
	{
		0x4A,
		{"BIT", {{"1", true}, {"D", true}}, 2}
	},
	{
		0x4B,
		{"BIT", {{"1", true}, {"E", true}}, 2}
	},
	{
		0x4C,
		{"BIT", {{"1", true}, {"H", true}}, 2}
	},
	{
		0x4D,
		{"BIT", {{"1", true}, {"L", true}}, 2}
	},
	{
		0x4E,
		{"BIT", {{"1", true}, {"HL", false}}, 2}
	},
	{
		0x4F,
		{"BIT", {{"1", true}, {"A", true}}, 2}
	},

	//
	// 0x50 - 0x5F
	//
	{
		0x50,
		{"BIT", {{"2", true}, {"B", true}}, 2}
	},
	{
		0x51,
		{"BIT", {{"2", true}, {"C", true}}, 2}
	},
	{
		0x52,
		{"BIT", {{"2", true}, {"D", true}}, 2}
	},
	{
		0x53,
		{"BIT", {{"2", true}, {"E", true}}, 2}
	},
	{
		0x54,
		{"BIT", {{"2", true}, {"H", true}}, 2}
	},
	{
		0x55,
		{"BIT", {{"2", true}, {"L", true}}, 2}
	},
	{
		0x56,
		{"BIT", {{"2", true}, {"HL", false}}, 2}
	},
	{
		0x57,
		{"BIT", {{"2", true}, {"A", true}}, 2}
	},
	{
		0x58,
		{"BIT", {{"3", true}, {"B", true}}, 2}
	},
	{
		0x59,
		{"BIT", {{"3", true}, {"C", true}}, 2}
	},
	{
		0x5A,
		{"BIT", {{"3", true}, {"D", true}}, 2}
	},
	{
		0x5B,
		{"BIT", {{"3", true}, {"E", true}}, 2}
	},
	{
		0x5C,
		{"BIT", {{"3", true}, {"H", true}}, 2}
	},
	{
		0x5D,
		{"BIT", {{"3", true}, {"L", true}}, 2}
	},
	{
		0x5E,
		{"BIT", {{"3", true}, {"HL", false}}, 2}
	},
	{
		0x5F,
		{"BIT", {{"3", true}, {"A", true}}, 2}
	},

	//
	// 0x60 - 0x6F
	//
	{
		0x60,
		{"BIT", {{"4", true}, {"B", true}}, 2}
	},
	{
		0x61,
		{"BIT", {{"4", true}, {"C", true}}, 2}
	},
	{
		0x62,
		{"BIT", {{"4", true}, {"D", true}}, 2}
	},
	{
		0x63,
		{"BIT", {{"4", true}, {"E", true}}, 2}
	},
	{
		0x64,
		{"BIT", {{"4", true}, {"H", true}}, 2}
	},
	{
		0x65,
		{"BIT", {{"4", true}, {"L", true}}, 2}
	},
	{
		0x66,
		{"BIT", {{"4", true}, {"HL", false}}, 2}
	},
	{
		0x67,
		{"BIT", {{"4", true}, {"A", true}}, 2}
	},
	{
		0x68,
		{"BIT", {{"5", true}, {"B", true}}, 2}
	},
	{
		0x69,
		{"BIT", {{"5", true}, {"C", true}}, 2}
	},
	{
		0x6A,
		{"BIT", {{"5", true}, {"D", true}}, 2}
	},
	{
		0x6B,
		{"BIT", {{"5", true}, {"E", true}}, 2}
	},
	{
		0x6C,
		{"BIT", {{"5", true}, {"H", true}}, 2}
	},
	{
		0x6D,
		{"BIT", {{"5", true}, {"L", true}}, 2}
	},
	{
		0x6E,
		{"BIT", {{"5", true}, {"HL", false}}, 2}
	},
	{
		0x6F,
		{"BIT", {{"5", true}, {"A", true}}, 2}
	},

	//
	// 0x70 - 0x7F
	//
	{
		0x70,
		{"BIT", {{"6", true}, {"B", true}}, 2}
	},
	{
		0x71,
		{"BIT", {{"6", true}, {"C", true}}, 2}
	},
	{
		0x72,
		{"BIT", {{"6", true}, {"D", true}}, 2}
	},
	{
		0x73,
		{"BIT", {{"6", true}, {"E", true}}, 2}
	},
	{
		0x74,
		{"BIT", {{"6", true}, {"H", true}}, 2}
	},
	{
		0x75,
		{"BIT", {{"6", true}, {"L", true}}, 2}
	},
	{
		0x76,
		{"BIT", {{"6", true}, {"HL", false}}, 2}
	},
	{
		0x77,
		{"BIT", {{"6", true}, {"A", true}}, 2}
	},
	{
		0x78,
		{"BIT", {{"7", true}, {"B", true}}, 2}
	},
	{
		0x79,
		{"BIT", {{"7", true}, {"C", true}}, 2}
	},
	{
		0x7A,
		{"BIT", {{"7", true}, {"D", true}}, 2}
	},
	{
		0x7B,
		{"BIT", {{"7", true}, {"E", true}}, 2}
	},
	{
		0x7C,
		{"BIT", {{"7", true}, {"H", true}}, 2}
	},
	{
		0x7D,
		{"BIT", {{"7", true}, {"L", true}}, 2}
	},
	{
		0x7E,
		{"BIT", {{"7", true}, {"HL", false}}, 2}
	},
	{
		0x7F,
		{"BIT", {{"7", true}, {"A", true}}, 2}
	},

	//
	// 0x80 - 0x8F
	//
	{
		0x80,
		{"RES", {{"0", true}, {"B", true}}, 2}
	},
	{
		0x81,
		{"RES", {{"0", true}, {"C", true}}, 2}
	},
	{
		0x82,
		{"RES", {{"0", true}, {"D", true}}, 2}
	},
	{
		0x83,
		{"RES", {{"0", true}, {"E", true}}, 2}
	},
	{
		0x84,
		{"RES", {{"0", true}, {"H", true}}, 2}
	},
	{
		0x85,
		{"RES", {{"0", true}, {"L", true}}, 2}
	},
	{
		0x86,
		{"RES", {{"0", true}, {"HL", false}}, 2}
	},
	{
		0x87,
		{"RES", {{"0", true}, {"A", true}}, 2}
	},
	{
		0x88,
		{"RES", {{"1", true}, {"B", true}}, 2}
	},
	{
		0x89,
		{"RES", {{"1", true}, {"C", true}}, 2}
	},
	{
		0x8A,
		{"RES", {{"1", true}, {"D", true}}, 2}
	},
	{
		0x8B,
		{"RES", {{"1", true}, {"E", true}}, 2}
	},
	{
		0x8C,
		{"RES", {{"1", true}, {"H", true}}, 2}
	},
	{
		0x8D,
		{"RES", {{"1", true}, {"L", true}}, 2}
	},
	{
		0x8E,
		{"RES", {{"1", true}, {"HL", false}}, 2}
	},
	{
		0x8F,
		{"RES", {{"1", true}, {"A", true}}, 2}
	},

	//
	// 0x90 - 0x9F
	//
	{
		0x90,
		{"RES", {{"2", true}, {"B", true}}, 2}
	},
	{
		0x91,
		{"RES", {{"2", true}, {"C", true}}, 2}
	},
	{
		0x92,
		{"RES", {{"2", true}, {"D", true}}, 2}
	},
	{
		0x93,
		{"RES", {{"2", true}, {"E", true}}, 2}
	},
	{
		0x94,
		{"RES", {{"2", true}, {"H", true}}, 2}
	},
	{
		0x95,
		{"RES", {{"2", true}, {"L", true}}, 2}
	},
	{
		0x96,
		{"RES", {{"2", true}, {"HL", false}}, 2}
	},
	{
		0x97,
		{"RES", {{"2", true}, {"A", true}}, 2}
	},
	{
		0x98,
		{"RES", {{"3", true}, {"B", true}}, 2}
	},
	{
		0x99,
		{"RES", {{"3", true}, {"C", true}}, 2}
	},
	{
		0x9A,
		{"RES", {{"3", true}, {"D", true}}, 2}
	},
	{
		0x9B,
		{"RES", {{"3", true}, {"E", true}}, 2}
	},
	{
		0x9C,
		{"RES", {{"3", true}, {"H", true}}, 2}
	},
	{
		0x9D,
		{"RES", {{"3", true}, {"L", true}}, 2}
	},
	{
		0x9E,
		{"RES", {{"3", true}, {"HL", false}}, 2}
	},
	{
		0x9F,
		{"RES", {{"3", true}, {"A", true}}, 2}
	},


	//
	// 0xA0 - 0xAF
	//
	{
		0xA0,
		{"RES", {{"4", true}, {"B", true}}, 2}
	},
	{
		0xA1,
		{"RES", {{"4", true}, {"C", true}}, 2}
	},
	{
		0xA2,
		{"RES", {{"4", true}, {"D", true}}, 2}
	},
	{
		0xA3,
		{"RES", {{"4", true}, {"E", true}}, 2}
	},
	{
		0xA4,
		{"RES", {{"4", true}, {"H", true}}, 2}
	},
	{
		0xA5,
		{"RES", {{"4", true}, {"L", true}}, 2}
	},
	{
		0xA6,
		{"RES", {{"4", true}, {"HL", false}}, 2}
	},
	{
		0xA7,
		{"RES", {{"4", true}, {"A", true}}, 2}
	},
	{
		0xA8,
		{"RES", {{"5", true}, {"B", true}}, 2}
	},
	{
		0xA9,
		{"RES", {{"5", true}, {"C", true}}, 2}
	},
	{
		0xAA,
		{"RES", {{"5", true}, {"D", true}}, 2}
	},
	{
		0xAB,
		{"RES", {{"5", true}, {"E", true}}, 2}
	},
	{
		0xAC,
		{"RES", {{"5", true}, {"H", true}}, 2}
	},
	{
		0xAD,
		{"RES", {{"5", true}, {"L", true}}, 2}
	},
	{
		0xAE,
		{"RES", {{"5", true}, {"HL", false}}, 2}
	},
	{
		0xAF,
		{"RES", {{"5", true}, {"A", true}}, 2}
	},

	//
	// 0xB0 - 0xBF
	//
	{
		0xB0,
		{"RES", {{"6", true}, {"B", true}}, 2}
	},
	{
		0xB1,
		{"RES", {{"6", true}, {"C", true}}, 2}
	},
	{
		0xB2,
		{"RES", {{"6", true}, {"D", true}}, 2}
	},
	{
		0xB3,
		{"RES", {{"6", true}, {"E", true}}, 2}
	},
	{
		0xB4,
		{"RES", {{"6", true}, {"H", true}}, 2}
	},
	{
		0xB5,
		{"RES", {{"6", true}, {"L", true}}, 2}
	},
	{
		0xB6,
		{"RES", {{"6", true}, {"HL", false}}, 2}
	},
	{
		0xB7,
		{"RES", {{"6", true}, {"A", true}}, 2}
	},
	{
		0xB8,
		{"RES", {{"7", true}, {"B", true}}, 2}
	},
	{
		0xB9,
		{"RES", {{"7", true}, {"C", true}}, 2}
	},
	{
		0xBA,
		{"RES", {{"7", true}, {"D", true}}, 2}
	},
	{
		0xBB,
		{"RES", {{"7", true}, {"E", true}}, 2}
	},
	{
		0xBC,
		{"RES", {{"7", true}, {"H", true}}, 2}
	},
	{
		0xBD,
		{"RES", {{"7", true}, {"L", true}}, 2}
	},
	{
		0xBE,
		{"RES", {{"7", true}, {"HL", false}}, 2}
	},
	{
		0xBF,
		{"RES", {{"7", true}, {"A", true}}, 2}
	},

	//
	// 0xC0 - 0xCF
	//
	{
		0xC0,
		{"SET", {{"0", true}, {"B", true}}, 2}
	},
	{
		0xC1,
		{"SET", {{"0", true}, {"C", true}}, 2}
	},
	{
		0xC2,
		{"SET", {{"0", true}, {"D", true}}, 2}
	},
	{
		0xC3,
		{"SET", {{"0", true}, {"E", true}}, 2}
	},
	{
		0xC4,
		{"SET", {{"0", true}, {"H", true}}, 2}
	},
	{
		0xC5,
		{"SET", {{"0", true}, {"L", true}}, 2}
	},
	{
		0xC6,
		{"SET", {{"0", true}, {"HL", false}}, 2}
	},
	{
		0xC7,
		{"SET", {{"0", true}, {"A", true}}, 2}
	},
	{
		0xC8,
		{"SET", {{"1", true}, {"B", true}}, 2}
	},
	{
		0xC9,
		{"SET", {{"1", true}, {"C", true}}, 2}
	},
	{
		0xCA,
		{"SET", {{"1", true}, {"D", true}}, 2}
	},
	{
		0xCB,
		{"SET", {{"1", true}, {"E", true}}, 2}
	},
	{
		0xCC,
		{"SET", {{"1", true}, {"H", true}}, 2}
	},
	{
		0xCD,
		{"SET", {{"1", true}, {"L", true}}, 2}
	},
	{
		0xCE,
		{"SET", {{"1", true}, {"HL", false}}, 2}
	},
	{
		0xCF,
		{"SET", {{"1", true}, {"A", true}}, 2}
	},

	//
	// 0xD0 - 0xDF
	//
	{
		0xD0,
		{"SET", {{"2", true}, {"B", true}}, 2}
	},
	{
		0xD1,
		{"SET", {{"2", true}, {"C", true}}, 2}
	},
	{
		0xD2,
		{"SET", {{"2", true}, {"D", true}}, 2}
	},
	{
		0xD3,
		{"SET", {{"2", true}, {"E", true}}, 2}
	},
	{
		0xD4,
		{"SET", {{"2", true}, {"H", true}}, 2}
	},
	{
		0xD5,
		{"SET", {{"2", true}, {"L", true}}, 2}
	},
	{
		0xD6,
		{"SET", {{"2", true}, {"HL", false}}, 2}
	},
	{
		0xD7,
		{"SET", {{"2", true}, {"A", true}}, 2}
	},
	{
		0xD8,
		{"SET", {{"3", true}, {"B", true}}, 2}
	},
	{
		0xD9,
		{"SET", {{"3", true}, {"C", true}}, 2}
	},
	{
		0xDA,
		{"SET", {{"3", true}, {"D", true}}, 2}
	},
	{
		0xDB,
		{"SET", {{"3", true}, {"E", true}}, 2}
	},
	{
		0xDC,
		{"SET", {{"3", true}, {"H", true}}, 2}
	},
	{
		0xDD,
		{"SET", {{"3", true}, {"L", true}}, 2}
	},
	{
		0xDE,
		{"SET", {{"3", true}, {"HL", false}}, 2}
	},
	{
		0xDF,
		{"SET", {{"3", true}, {"A", true}}, 2}
	},

	//
	// 0xE0 - 0xEF
	//
	{
		0xE0,
		{"SET", {{"4", true}, {"B", true}}, 2}
	},
	{
		0xE1,
		{"SET", {{"4", true}, {"C", true}}, 2}
	},
	{
		0xE2,
		{"SET", {{"4", true}, {"D", true}}, 2}
	},
	{
		0xE3,
		{"SET", {{"4", true}, {"E", true}}, 2}
	},
	{
		0xE4,
		{"SET", {{"4", true}, {"H", true}}, 2}
	},
	{
		0xE5,
		{"SET", {{"4", true}, {"L", true}}, 2}
	},
	{
		0xE6,
		{"SET", {{"4", true}, {"HL", false}}, 2}
	},
	{
		0xE7,
		{"SET", {{"4", true}, {"A", true}}, 2}
	},
	{
		0xE8,
		{"SET", {{"5", true}, {"B", true}}, 2}
	},
	{
		0xE9,
		{"SET", {{"5", true}, {"C", true}}, 2}
	},
	{
		0xEA,
		{"SET", {{"5", true}, {"D", true}}, 2}
	},
	{
		0xEB,
		{"SET", {{"5", true}, {"E", true}}, 2}
	},
	{
		0xEC,
		{"SET", {{"5", true}, {"H", true}}, 2}
	},
	{
		0xED,
		{"SET", {{"5", true}, {"L", true}}, 2}
	},
	{
		0xEE,
		{"SET", {{"5", true}, {"HL", false}}, 2}
	},
	{
		0xEF,
		{"SET", {{"5", true}, {"A", true}}, 2}
	},

	//
	// 0xF0 - 0xFA
	//
	{
		0xF0,
		{"SET", {{"6", true}, {"B", true}}, 2}
	},
	{
		0xF1,
		{"SET", {{"6", true}, {"C", true}}, 2}
	},
	{
		0xF2,
		{"SET", {{"6", true}, {"D", true}}, 2}
	},
	{
		0xF3,
		{"SET", {{"6", true}, {"E", true}}, 2}
	},
	{
		0xF4,
		{"SET", {{"6", true}, {"H", true}}, 2}
	},
	{
		0xF5,
		{"SET", {{"6", true}, {"L", true}}, 2}
	},
	{
		0xF6,
		{"SET", {{"6", true}, {"HL", false}}, 2}
	},
	{
		0xF7,
		{"SET", {{"6", true}, {"A", true}}, 2}
	},
	{
		0xF8,
		{"SET", {{"7", true}, {"B", true}}, 2}
	},
	{
		0xF9,
		{"SET", {{"7", true}, {"C", true}}, 2}
	},
	{
		0xFA,
		{"SET", {{"7", true}, {"D", true}}, 2}
	},
	{
		0xFB,
		{"SET", {{"7", true}, {"E", true}}, 2}
	},
	{
		0xFC,
		{"SET", {{"7", true}, {"H", true}}, 2}
	},
	{
		0xFD,
		{"SET", {{"7", true}, {"L", true}}, 2}
	},
	{
		0xFE,
		{"SET", {{"7", true}, {"HL", false}}, 2}
	},
	{
		0xFF,
		{"SET", {{"7", true}, {"A", true}}, 2}
	}
};