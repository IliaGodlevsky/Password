#ifndef FUNCT_H_
#define FUNCT_H_

#include <string>

// pointers to a function
using has_char = bool(*)(const std::string&);
using options = void(*)(const char*);

// 'has' functions
bool has_letters(const std::string& pass);
bool has_digits(const std::string& pass);
bool has_symbols(const std::string& pass);
bool has_digits_letters(const std::string& pass);
bool has_letters_symbols(const std::string& pass);
bool has_digits_symbols(const std::string& pass);
bool has_symbols_digits_letters(const std::string& pass);

// menu functions
void mode_menu(const char* msg);
void menu(const char* msg);
void range(unsigned upper, unsigned bottom);

// input functions
unsigned set_option(options menu, const char* msg, 
	unsigned upper = 1, unsigned bottom = 0);
unsigned input(unsigned upper, 
	unsigned bottom, const char* msg);
bool wrong(unsigned choice, 
	unsigned upper, unsigned bottom);
std::string save_path();
void eat_line();
#endif
