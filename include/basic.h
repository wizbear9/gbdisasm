#pragma once

#include <string>
#include <vector>
#include <map>

struct Operand {
	std::string name;
	//int bytes;
	bool is_imm;
};

class Instruction
{
public:
	std::string mnemonic;
	std::vector<Operand> op;
	int bytes;

	static std::map<int, Instruction> table;
	static std::map<int, Instruction> table_cbpfx;	// 0xCB prefixed
};