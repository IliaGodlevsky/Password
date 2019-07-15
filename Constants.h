#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include "Functions.h"

static constexpr unsigned NOT_FOUND = string::npos;

static const char* ans = "One more";
static const char* mode_msg = "Choose mode";
static const char* length_msg = "Enter length of the password";
static const char* example_msg = "Enter number of examples";
static const char* save_folder = "Save/";

static const string lower_letters = "abcdefghijklmnopqrstuvwxyz";
static const string upper_letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static const string letters = lower_letters + upper_letters;
static const string symbols = "![]{}|%*()?@#$~&";
static const string digits = "0123456789";

enum {
	NO, YES,
	MIN_LENGTH = 3,
	MIN_MODE = 1,
	MODES = 7,
	EXAMPLES_MAX = 50,
	EXAMPLES_MIN = 10
};

static const string strings[MODES] {
	letters,
	digits,
	symbols,
	digits + letters,
	letters + symbols, 
	digits + symbols,
	digits + letters + symbols 
};

static const unsigned lengths[MODES] {
	letters.size(),
	digits.size(),
	symbols.size(),
	digits.size() + letters.size(),
	letters.size() + symbols.size(),
	digits.size() + symbols.size(),
	letters.size() + symbols.size() + digits.size()
};

static const has_char has[MODES]{
	has_letters,
	has_digits,
	has_symbols,
	has_digits_letters,
	has_letters_symbols,
	has_digits_symbols,
	has_symbols_digits_letters
};
#endif
