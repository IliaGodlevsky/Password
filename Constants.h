#ifndef CONSTANTS_H_
#define CONSTANTS_H_
#include "Functions.h"
namespace password
{
	enum {
		MIN_LENGTH = 4,
		MODES = 7,
		SYMBOLS_TYPES = 4,
		EXAMPLES_MAX = 200,
		EXAMPLES_MIN = 5
	};
	enum
	{
		LETTERS_LENGTH = 52,
		DIGITS_LENGTH = 9,
		SYMBOLS_LENGTH = 14,
		DIGITS_AND_LETTERS_LENGTH = DIGITS_LENGTH + LETTERS_LENGTH,
		LETTRS_AND_SYMBOLS_LENGTH = LETTERS_LENGTH + SYMBOLS_LENGTH,
		DIGITS_AND_SYMBOLS_LENGTH = DIGITS_LENGTH + SYMBOLS_LENGTH,
		DIGITS_AND_LETTERS_AND_SYMBOLS_LENGTH = DIGITS_LENGTH + SYMBOLS_LENGTH + LETTERS_LENGTH,
	};
	static const int lengths[MODES] = {
		LETTERS_LENGTH,
		DIGITS_LENGTH,
		SYMBOLS_LENGTH,
		DIGITS_AND_LETTERS_LENGTH,
		LETTRS_AND_SYMBOLS_LENGTH,
		DIGITS_AND_SYMBOLS_LENGTH,
		DIGITS_AND_LETTERS_AND_SYMBOLS_LENGTH,
	};
	static const is_char is[MODES] = {
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
	static const char* symbols = "![]{}|%*)?@#$~![]{}|%*)?@#$~";
	static const char* digits = "01234567890123456789";
	static const char* chars[SYMBOLS_TYPES] = {
		upper_letters,lower_letters,digits,symbols };
	static const char* filename = "Passwords.txt";
}
#endif