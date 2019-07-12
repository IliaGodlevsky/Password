#ifndef FUNCT_H_
#define FUNCT_H_
#include <string>
using has_char = bool(*)(const std::string&);
using settings = void(*)(const char*);
// 'has' functions
bool has_letters(const std::string& pass);
bool has_digits(const std::string& pass);
bool has_symbols(const std::string& pass);
bool has_digits_and_letters(const std::string& pass);
bool has_letters_and_symbols(const std::string& pass);
bool has_digits_and_symbols(const std::string& pass);
bool has_symbols_digits_and_letters(const std::string& pass);
// menu functions
void mode_menu(const char* msg);
void menu(const char* msg);
void range(unsigned upper, unsigned bottom);
// input functions
int set_option(settings menu, unsigned upper, unsigned bottom, const char* msg);
int input(unsigned upper, unsigned bottom, const char* msg);
bool wrong(unsigned choice, unsigned upper, unsigned bottom);
void eat_line();
#endif
