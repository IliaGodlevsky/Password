#ifndef FUNCT_H_
#define FUNCT_H_
#include <string>
using is_char = int(*)(int);
using has_char = bool(*)(const std::string&);

bool has_letters(const std::string& pass);
bool has_digits(const std::string& pass);
bool has_symbols(const std::string& pass);
bool has_digits_and_letters(const std::string& pass);
bool has_letters_and_symbols(const std::string& pass);
bool has_digits_and_symbols(const std::string& pass);
bool has_symbols_digits_and_letters(const std::string& pass);
int input(int upper, int bottom);
bool wrong(int choice, int upper, int bottom);
int issymbol(int symbol);
int isdigit_or_letter(int symbol);
int isletter_or_symbol(int symbol);
int isdigit_or_symbol(int symbol);
int isletter_or_digit_or_symbol(int symbol);
void length_menu();
void mode_menu();
void eat_line();
std::string password_symbols();
#endif
