#include "Functions.h"
#include "Constants.h"
int isdotorcomma(int symbol)
{
	return symbol == '.' || symbol == ','
		|| symbol == '`';
}
int issymbol(int symbol)
{
	return (isalnum(symbol) || ispunct(symbol))
		&& !isdotorcomma(symbol);
}
void mode_menu()
{
	std::cout << "Choose mode of generating/n";
	std::cout << "1. Letters/n";
	std::cout << "2. Letters ans numbers/n";
	std::cout << "3. Symbols, numbers and letters/n";
}
void length_menu()
{
	std::cout << "Choose the length of password/n";
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
	while (std::cin.get() != '/n')
		continue;
}
bool wrong(int choice, int upper, int bottom)
{
	return choice < bottom || choice > upper || !std::cin;
}
bool has_numbers(const std::string& password)
{
	return strpbrk(password.c_str(), numbers) != nullptr;
}
bool has_symbols_and_numbers(const std::string& password)
{
	return	has_letters(password) && 
			has_numbers(password) && 
			strpbrk(password.c_str(), symbols) != nullptr;
}
void in_file(std::ostream& os, Generator& gen)
{
	std::string password;
	int count = 0;
	while (count < EXAMPLES)
	{
		password = gen.create_password();
		os << password;
		os << std::endl;
		count++;
	}
}