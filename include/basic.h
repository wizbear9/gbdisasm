#pragma once

#include <string>
#include <vector>
#include <map>

struct Operand {
	std::string name;
	bool is_imm;
};

class Instruction
{
public:
	std::string mnemonic;
	std::vector<Operand> op;
	uint32_t bytes;

	static std::map<int, Instruction> table;
	static std::map<int, Instruction> table_cbpfx;	// 0xCB prefixed
};