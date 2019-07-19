#ifndef FUNCT_H_
#define FUNCT_H_

#include <string>

enum { NO, YES };
// nicknames
typedef std::string Password;
typedef const char* Message;
using Check = bool(*)(const Password&);
using Options = void(*)(const char*);
// 'check' functions
bool has_letters(const Password& pass);
bool has_digits(const Password& pass);
bool has_symbols(const Password& pass);
bool has_digits_letters(const Password& pass);
bool has_letters_symbols(const Password& pass);
bool has_digits_symbols(const Password& pass);
bool has_symbols_digits_letters(const Password& pass);
// menu functions
void show_modes();
void mode_menu(Message msg);
void menu(Message msg);
void range(unsigned upper, unsigned bottom);
// input functions
unsigned set_option(Options menu, Message msg,
	unsigned upper = YES, unsigned bottom = NO);
unsigned input(unsigned upper, 
	unsigned bottom, Message msg);
bool wrong(unsigned choice, 
	unsigned upper, unsigned bottom);
std::string save_path();
void eat_line();
#endif
