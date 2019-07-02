#include <iostream>
#include "Functions.h"
#include "Constants.h"
void mode_menu()
{
	std::cout << "Choose mode of generating\n";
	std::cout << "1. Letters\n";
	std::cout << "2. Letters ans numbers\n";
	std::cout << "3. Symbols, numbers and letters\n";
}
void length_menu()
{
	std::cout << "Choose the length of password\n";
	std::cout << "Max length is: " << MAX_LENGTH << std::endl;
	std::cout << "Min length is: " << MIN_LENGTH << std::endl;
	std::cout << "Length: ";
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
	return choice < bottom || choice > upper || !std::cin;
}
int issymbol(int symbol)
{
	return isalnum(symbol) || strchr(symbols, symbol) != nullptr;
}
bool has_numbers(const std::string& pass)
{
	return strpbrk(pass.c_str(), numbers) != nullptr;
}
bool has_symbols_and_numbers(const std::string& pass)
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