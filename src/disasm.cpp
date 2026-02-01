#include "disasm.h"
#include "basic.h"
#include <iostream>
#include <iomanip>
#include <fstream>

Disassembler::Disassembler()
	: cursor(0)
	, main_point(0)
{
}

void Disassembler::run(char* file_name)
{
	if (!read_gbrom(file_name)) {
		std::cout << "An error occurred while reading the file.\n";
		return;
	}

	cursor = entry_point;

	// 1. read entry point
	unsigned char entry_bytes[4];
	unsigned int n;

	read_bytes(4, n);
	entry_bytes[0] = (n >> 24) & 0xFF;
	entry_bytes[1] = (n >> 16) & 0xFF;
	entry_bytes[2] = (n >> 8) & 0xFF;
	entry_bytes[3] = n & 0xFF;

	main_point = entry_bytes[0] << 8 | entry_bytes[1];
	cursor = main_point;

	// 2. disassemble code
	disassemble();

	// 3. print instruction
	print_instruction();
}

void Disassembler::disassemble()
{
	for (int i = 0; i < 5000; ++i) {
		unsigned char bt = read_byte();
		std::vector<unsigned char> inst;
		inst.emplace_back(bt);
		if (bt != 0xCB) {
			int byte_count = Instruction::table[bt].bytes;
			for (int i = 0; i < byte_count - 1; ++i)
				inst.emplace_back(read_byte());
		}
		else {
			inst.emplace_back(read_byte());
		}
		inst_list.emplace_back(inst);
	}
}

void Disassembler::print_instruction()
{
	int offset = main_point;
	for (int i = 0; i < inst_list.size(); ++i) {
		std::cout << std::uppercase << std::hex << std::setfill('0') <<
			std::setw(8) << static_cast<unsigned>(offset) << ' ';

		auto inst = inst_list[i];
		for (int j = 0; j < inst.size(); ++j) {
			std::cout << std::uppercase << std::hex << std::setfill('0') <<
				std::setw(2) << static_cast<unsigned>(inst[j]);
		}
		std::cout << '\t';
		unsigned char opcode = inst[0];
		Instruction& entry = (opcode == 0xCB) ?
			Instruction::table_cbpfx[inst[1]] : Instruction::table[opcode];
		if (opcode == 0xCB) opcode = inst[1];

		std::cout << entry.mnemonic << ' ';
		for (int j = 0; j < entry.op.size(); ++j) {
			auto op = entry.op[j];
			if (!op.is_imm) std::cout << "(";
			if (op.name == "n8") {
				std::cout << "$";
				std::cout << std::uppercase << std::hex << std::setfill('0') <<
					std::setw(2) << static_cast<unsigned>(inst[1]);
			}
			else if (op.name == "n16") {
				std::cout << "$";
				std::cout << std::uppercase << std::hex << std::setfill('0') <<
					std::setw(2) << static_cast<unsigned>((inst[2] << 8 | inst[1]));
			}
			else {
				std::cout << op.name;
			}
			if (!op.is_imm) std::cout << ")";
			std::cout << ' ';
		}

		std::cout << '\n';
		offset += Instruction::table[opcode].bytes;
	}
}

bool Disassembler::read_gbrom(char* file_name)
{
	std::ifstream file(file_name, std::ios::binary | std::ios::ate);
	std::streamsize size = file.tellg();
	file.seekg(0, std::ios::beg);

	if (file.bad())
		return false;

	buffer.resize(size);
	file.read(buffer.data(), size);

	return true;
}

bool Disassembler::read_bytes(int n, unsigned int& bts)
{
	if (n <= 0 || n > sizeof(int))
		return false;

	unsigned char temp[sizeof(int)] = { 0 };
	for (int i = 0; i < n; ++i)
		temp[i] = read_byte();
	memcpy(&bts, temp, n);

	return true;
}