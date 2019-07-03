#pragma once
#ifndef CONSTANTS_H_
#define CONSTANTS_H_
#include <vector>
#include "Functions.h"
enum { LETTERS, NUMBERS, SYMBOLS };
static const int MIN_LENGTH = 6;	// WARNING: do not make it equal less than 4. Endless loop alert!
static const int MAX_LENGTH = 25;
static const int MODES = 3;
static const int SYMBOLS_TYPES = 4;
static const int EXAMPLES = 25;
static const is_char status[MODES] = { isalpha,isalnum, issymbol };
static const has_char has[MODES] = { has_letters, has_numbers,has_symbols };
static const char* lower_letters = "abcdefghijklmnopqrstuvwxyz";
static const char* upper_letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static const char* symbols = "|%*)?@#$~|%*)?@#$~";
static const char* numbers = "01234567890123456789";
static const char* filename = "Passwords.txt";
#endif