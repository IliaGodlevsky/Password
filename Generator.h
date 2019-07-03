#ifndef GEN_H_
#define GEN_H_
#include <string>
#include <cctype>
#include <iostream>
#include "Constants.h"
#include "Functions.h"
class Generator
{
private:
	unsigned int mode;
	unsigned int length;
protected:
	// arrays of pointer to function
	is_char status[MODES] = { isalpha,isalnum,
		issymbol };
	has_char has_symbols[MODES] = { has_letters,
		has_numbers,has_symbols_and_numbers };
public:
	Generator(int mode, int length);
	std::string generate(is_char is);
	std::string password(has_char has);
	std::string create_password();
	void in_file(std::ostream& os, int examples);
};
#endif