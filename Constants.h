#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include "Functions.h"

#define CONST static const

CONST size_t NOT_FOUND = std::string::npos;

CONST char* answer = "One more";
CONST char* mode_msg = "Choose mode";
CONST char* length_msg = "Enter length of the password";
CONST char* example_msg = "Enter number of examples";
CONST char* save_folder = "Save/";

CONST std::string lower_letters = "abcdefghijklmnopqrstuvwxyz";
CONST std::string upper_letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
CONST std::string letters = lower_letters + upper_letters;
CONST std::string symbols = "![]{}|%*()?@#$~&";
CONST std::string digits = "0123456789";

enum 
{
	MIN_LENGTH = 3,
	MIN_MODE = 1,
	MODES = 7,
	EXAMPLES_MAX = 50,
	EXAMPLES_MIN = 10
};

CONST std::string strings[MODES] 
{
	letters,
	digits,
	symbols,
	digits + letters,
	letters + symbols, 
	digits + symbols,
	digits + letters + symbols 
};

CONST size_t lengths[MODES] 
{
	letters.size(),
	digits.size(),
	symbols.size(),
	digits.size() + letters.size(),
	letters.size() + symbols.size(),
	digits.size() + symbols.size(),
	letters.size() + symbols.size() + digits.size()
};

CONST Control control[MODES]
{
	has_letters,
	has_digits,
	has_symbols,
	has_digits_letters,
	has_letters_symbols,
	has_digits_symbols,
	has_symbols_digits_letters
};
#endif
