#include <iostream>
#include <cstring>
#include <vector>
#include "Functions.h"
#include "Constants.h"
void mode_menu()
{
	std::cout << "Choose mode of generating\n";
	std::cout << "1. letters\n";
	std::cout << "2. numbers\n";
	std::cout << "3. symbols\n";
}
void length_menu()
{
	std::cout << "Enter length of password";
	std::cout << " (" << MIN_LENGTH << " - ";
	std::cout << MAX_LENGTH << "): ";
}
int input(int upper, int bottom)
{
	int choice;
	std::cin >> choice;
	while (wrong(choice, upper, bottom))
	{
		eat_line();
		std::cin >> choice;
	}
	return choice - 1;
}
void eat_line()
{
	std::cin.clear();
	while (std::cin.get() != '\n')
		continue;
}
bool wrong(int choice, int upper, int bottom)
{
	return 
		choice < bottom || 
		choice > upper || 
		!std::cin;
}
int issymbol(int symbol)
{
	return 
		isalpha(symbol) || isalnum(symbol) || 
		strchr(symbols, symbol) != nullptr;
}
bool has_letters(const std::string& pass)
{
	return
		strpbrk(pass.c_str(), lower_letters) != nullptr &&
		strpbrk(pass.c_str(), upper_letters) != nullptr;
}
bool has_numbers(const std::string& pass)
{
	return 
		has_letters(pass) && 
		strpbrk(pass.c_str(), numbers) != nullptr;
}
bool has_symbols(const std::string& pass)
{
	return
		has_letters(pass) &&
		has_numbers(pass) &&
		strpbrk(pass.c_str(), symbols) != nullptr;
}
std::string password_symbols()
{
	const char* chars[SYMBOLS_TYPES] = {
		upper_letters,
		lower_letters,
		numbers,
		symbols };
	std::string word;
	for (int i = 0; i < SYMBOLS_TYPES; i++)
		word += chars[i];
	return word;
}
void report(int length, int mode, int examples)
{
	std::cout << "Password length: " << length + 1 << "\n";
	std::cout << "Mode of creating: ";
	switch (mode)
	{
	case LETTERS: std::cout << "only letters\n"; break;
	case NUMBERS: std::cout << "numbers and letters\n"; break;
	case SYMBOLS: std::cout << "symbols, numbers and letters\n"; break;
	}
	std::cout << "File: " << filename << std::endl;
}