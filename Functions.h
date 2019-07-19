#ifndef FUNCT_H_
#define FUNCT_H_

#include <string>

using Word = std::string;
using Control = bool(*)(const std::string&);
using Options = void(*)(const char*);

// 'has' functions
bool has_letters(const Word& pass);
bool has_digits(const Word& pass);
bool has_symbols(const Word& pass);
bool has_digits_letters(const Word& pass);
bool has_letters_symbols(const Word& pass);
bool has_digits_symbols(const Word& pass);
bool has_symbols_digits_letters(const Word& pass);

// menu functions
void mode_menu(const char* msg);
void menu(const char* msg);
void range(size_t upper, size_t bottom);

// input functions
size_t set_option(Options menu, const char* msg, 
	size_t upper = 1, size_t bottom = 0);
size_t input(size_t upper, 
size_t bottom, const char* msg);
bool wrong(size_t choice, 
	size_t upper, size_t bottom);
std::string save_path();
void eat_line();
#endif
