#ifndef CONSTANTS_H_
#define CONSTANTS_H_
#include "Functions.h"
enum {
	MIN_LENGTH = 4,
	MAX_LENGTH = 18,
	MODES = 7,
	SYMBOLS_TYPES = 4,
	EXAMPLES = 25
};
static const is_char status[MODES] = {
	isalpha,
	isdigit,
	issymbol,
	isdigit_or_letter,
	isletter_or_symbol,
	isdigit_or_symbol,
	isletter_or_digit_or_symbol
};
static const has_char has[MODES] = {
	has_letters,
	has_digits,
	has_symbols,
	has_digits_and_letters,
	has_letters_and_symbols,
	has_digits_and_symbols,
	has_symbols_digits_and_letters
};
static const char* lower_letters = "abcdefghijklmnopqrstuvwxyz";
static const char* upper_letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static const char* symbols = "|%*)?@#$~|%*)?@#$~";
static const char* numbers = "01234567890123456789";
static const char* chars[SYMBOLS_TYPES] = { 
	upper_letters,lower_letters,numbers,symbols };
static const char* filename = "Passwords.txt";
#endif