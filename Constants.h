#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include "Functions.h"

static constexpr unsigned NOT_FOUND = std::string::npos;

static const char* answer = "One more";
static const char* mode_msg = "Choose mode";
static const char* length_msg = "Enter length of the password";
static const char* example_msg = "Enter number of examples";
static const char* save_folder = "Save/";

static const std::string lower_letters = "abcdefghijklmnopqrstuvwxyz";
static const std::string upper_letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static const std::string letters = lower_letters + upper_letters;
static const std::string symbols = "![]{}|%*()?@#$~&";
static const std::string digits = "0123456789";

enum 
{
	MIN_LENGTH = 3,
	MIN_MODE = 1,
	MODES = 7,
	EXAMPLES_MAX = 50,
	EXAMPLES_MIN = 10
};

static const std::string strings[MODES] 
{
	letters,
	digits,
	symbols,
	digits + letters,
	letters + symbols, 
	digits + symbols,
	digits + letters + symbols 
};

static const unsigned lengths[MODES] 
{
	letters.size(),
	digits.size(),
	symbols.size(),
	digits.size() + letters.size(),
	letters.size() + symbols.size(),
	digits.size() + symbols.size(),
	letters.size() + symbols.size() + digits.size()
};

static const has_char has[MODES]
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
