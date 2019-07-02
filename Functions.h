#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
int input(int upper, int bottom);
int isdotorcomma(int symbol);
int issymbol(int symbol);
void length_menu();
void mode_menu();
void eat_line();
bool wrong(int choice,int upper, int bottom);
bool has_letters(const std::string& password) { return true; }
bool has_numbers(const std::string& password);
bool has_symbols_and_numbers(const std::string& password);
void in_file(std::ostream& os, Generator& gen);
#endif