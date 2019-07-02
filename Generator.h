#ifndef GEN_H_
#define GEN_H_
#include <string>
#include <cctype>
#include <iostream>
#include "Constants.h"
inline bool has_letters(const std::string& pass) { return true; }
bool has_numbers(const std::string& pass);
bool has_symbols_and_numbers(const std::string& pass);
int isdotorcomma(int symbol);
int issymbol(int symbol);
std::string password_symbols();
class Generator
{
private:
	enum Mode {
		LETTERS,
		NUMBERS_AND_LETTERS,
		ALL_SYMBOLS
	};
	Mode mode;
	unsigned int length;
	int(*status[MODES])(int) = { isalpha,isalnum,issymbol };
	bool(*has_symbols[MODES])(const std::string&)  = 
	{ has_letters,has_numbers,has_symbols_and_numbers };
public:
	Generator(int mode, int length);
	std::string generate(int(*status)(int));
	std::string password(bool(*has_symbols)(const std::string&));
	std::string create_password();
};
#endif