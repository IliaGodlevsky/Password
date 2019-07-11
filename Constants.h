#ifndef CONSTANTS_H_
#define CONSTANTS_H_
#include "Functions.h"
namespace password
{
	enum game_constants {
		MIN_LENGTH = 4,
		MODES = 7,
		EXAMPLES_MAX = 200,
		EXAMPLES_MIN = 5
	};
	enum password_length
	{
		LETTERS_LENGTH = 52,
		DIGITS_LENGTH = 9,
		SYMBOLS_LENGTH = 16,
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
		isalnum,
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
	static const std::string lower_letters = "abcdefghijklmnopqrstuvwxyz";
	static const std::string upper_letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	static const std::string letters = lower_letters + upper_letters;
	static const std::string symbols = "-+![]{}|%*)?@#$~";
	static const std::string digits = "0123456789";
	static const std::string strings[MODES] = {
		letters,
		digits,
		symbols,
		digits + letters,
		letters + symbols, 
		digits + symbols,
		digits + letters + symbols 
	};
	static const char* filename = "Passwords.txt";
}
#endif