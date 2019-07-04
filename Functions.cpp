#include <iostream>
#include <cstring>
#include <algorithm>
#include "Functions.h"
#include "Constants.h"
void mode_menu()
{
	std::cout << "Choose mode of generating\n";
	std::cout << "1. only letters\n";
	std::cout << "2. only digits\n";
	std::cout << "3. only symbols\n";
	std::cout << "4. digits and letters\n";
	std::cout << "5. letters and symbols\n";
	std::cout << "6. digits and symbols\n";
	std::cout << "7. symbols, digits and letters\n";
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
	return strchr(symbols, symbol) != nullptr;
}
int isdigit_or_letter(int symbol)
{
	return isdigit(symbol) || isalpha(symbol);
}
int isletter_or_symbol(int symbol)
{
	return isalpha(symbol) || issymbol(symbol);
}
int isdigit_or_symbol(int symbol)
{
	return isdigit(symbol) || issymbol(symbol);
}
int isletter_or_digit_or_symbol(int symbol)
{
	return isdigit(symbol) || issymbol(symbol) || isalpha(symbol);
}
bool has_letters(const std::string& pass)
{
	return 
		strpbrk(pass.c_str(), lower_letters) != nullptr &&
		strpbrk(pass.c_str(), upper_letters) != nullptr;
}
bool has_digits(const std::string& pass)
{
	return strpbrk(pass.c_str(), numbers) != nullptr;
}
bool has_symbols(const std::string& pass)
{
	return strpbrk(pass.c_str(), symbols) != nullptr;
}
bool has_digits_and_letters(const std::string& pass)
{
	return has_digits(pass) && has_letters(pass);
}
bool has_letters_and_symbols(const std::string& pass)
{
	return has_letters(pass) && has_symbols(pass);
}
bool has_digits_and_symbols(const std::string& pass)
{
	return has_digits(pass) && has_symbols(pass);
}
bool has_symbols_digits_and_letters(const std::string& pass)
{
	return has_letters(pass) && has_digits(pass) && has_symbols(pass);
}
std::string password_symbols()
{
	std::string word;
	for (int i = 0; i < SYMBOLS_TYPES; i++)
		word += chars[i];
	std::random_shuffle(word.begin(), word.end());
	return word;
}