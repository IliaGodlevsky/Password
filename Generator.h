#ifndef GENERATOR_H_
#define GENERATOR_H_
#include <string>
#include <cctype>
#include <iostream>
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
	std::string word;
public:
	Generator(const Options& opt);
	std::string generate(int(*status)(int));
	std::string password(bool(*has_symbols)(const std::string&));
	std::string create_password();
};
#endif