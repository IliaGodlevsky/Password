#ifndef FUNCT_H_
#define FUNCT_H_
#include <string>
using std::string;
using has_char = bool(*)(const string&);
using settings = void(*)(const char*);
// 'has' functions
bool has_letters(const string& pass);
bool has_digits(const string& pass);
bool has_symbols(const string& pass);
bool has_digits_letters(const string& pass);
bool has_letters_symbols(const string& pass);
bool has_digits_symbols(const string& pass);
bool has_symbols_digits_letters(const string& pass);
// menu functions
void mode_menu(const char* msg);
void menu(const char* msg);
void range(unsigned upper, unsigned bottom);
// input functions
unsigned set_option(settings menu, unsigned upper, unsigned bottom, const char* msg);
unsigned input(unsigned upper, unsigned bottom, const char* msg);
bool wrong(unsigned choice, unsigned upper, unsigned bottom);
void eat_line();
#endif
