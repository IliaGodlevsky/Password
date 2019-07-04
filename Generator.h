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
public:
	Generator(unsigned mode, unsigned length) :
		mode(mode), length(length) {}
	std::string generate(is_char is);
	std::string password(has_char has);
	std::string create_password();
	void in_file(std::ostream& os, unsigned examples);
};
#endif