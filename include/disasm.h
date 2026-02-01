#pragma once

#include <vector>
#include "basic.h"

class Disassembler
{
public:
	Disassembler();
	//
	// Method
	//
	void run(char*);

	//
	// Member
	//
	const int entry_point = 0x0100;

private:
	//
	// Method
	//
	bool read_gbrom(char*);

	void disassemble();
	void print_instruction();

	unsigned char read_byte();
	bool read_bytes(int n, unsigned int&);

	//
	// Member
	//
	std::vector<char> buffer;
	int cursor;

	int main_point;

	std::vector<std::vector<unsigned char>> inst_list;
};

inline unsigned char Disassembler::read_byte()
{
	return buffer[cursor++];
}