#ifndef FUNCT_H_
#define FUNCT_H_
#include <string>
using is_char = int(*)(int);
using has_char = bool(*)(const std::string&);

bool has_letters(const std::string& pass);
bool has_symbols_and_numbers(const std::string& pass);
bool wrong(int choice, int upper, int bottom);
bool has_numbers(const std::string& pass);
int input(int upper, int bottom);
int issymbol(int symbol);
void length_menu();
void mode_menu();
void eat_line();
std::string password_symbols();
#endif
