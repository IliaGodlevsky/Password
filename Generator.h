#ifndef GENERATOR_H_
#define GENERATOR_H_
#include <string>
#include <cctype>
#include <iostream>
const int MAX_LENGTH = 15;
const int MODES = 3;
const int EXAMPLES = 100;
static const char* filename = "Password.txt";
using isfunct = int(*)(int);
int issymbol(int symbol);
int isdotorcomma(int symbol);
class Generator
{
private:
	enum Mode { 
		LETTERS, 
		NUMBERS_AND_LETTERS, 
		ALL_SYMBOLS 
	};
	Mode mode;
	int length;
	isfunct status[MODES] = { isalpha,isalnum,issymbol };
	std::string word;
public:
	Generator(int mode_, int size) 
		: mode(Mode(mode_)), length(size) {}
	std::string generate(isfunct status);
	std::string password() { return generate(status[mode]); }
};
#endif