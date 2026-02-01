#include <iostream>
#include "disasm.h"

int main(int argc, char* argv[])
{
	if (argc != 2) {
		std::cout << "usage: " << argv[0] << " file_name\n";
		return -1;
	}

	Disassembler disasm;
	disasm.run(argv[1]);

	return 0;
}