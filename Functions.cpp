#include <iostream>

#include "Functions.h"
#include "Constants.h"

bool has_letters(const Word& pass) 
{ 
	return letters.find_first_of(pass) != NOT_FOUND;
}

bool has_digits(const Word& pass) 
{ 
	return digits.find_first_of(pass) != NOT_FOUND;
}

bool has_symbols(const Word& pass) 
{ 
	return symbols.find_first_of(pass) != NOT_FOUND;
}

bool has_digits_letters(const Word& pass) 
{ 
	return has_digits(pass) && has_letters(pass); 
}

bool has_letters_symbols(const Word& pass) 
{ 
	return has_letters(pass) && has_symbols(pass); 
}

bool has_digits_symbols(const Word& pass) 
{ 
	return has_digits(pass) && has_symbols(pass); 
}

bool has_symbols_digits_letters(const Word& pass) 
{ 
	return has_digits_letters(pass) && has_symbols(pass); 
}

void mode_menu(const char* msg) 
{
	std::cout << "Modes of generating\n"
		<< "1. only letters\n"
		<< "2. only digits\n"
		<< "3. only symbols\n"
		<< "4. digits and letters\n"
		<< "5. letters and symbols\n"
		<< "6. digits and symbols\n"
		<< "7. symbols, digits and letters\n"
		<< msg;
}

void menu(const char* msg) { std::cout << msg; }

void range(size_t upper, size_t bottom) 
{
	std::cout << " (" << bottom << " - " << upper << "): ";
}

size_t set_option(Options menu, 
	const char* msg, size_t upper, size_t bottom) 
{
	menu(msg);
	range(upper, bottom);
	return input(upper, bottom, msg);
}

size_t input(size_t upper, 
	size_t bottom, const char* msg) 
{
	size_t choice;
	std::cin >> choice;
	while (wrong(choice, upper, bottom))
	{
		eat_line();
		std::cout << msg;
		range(upper, bottom);
		std::cin >> choice;
	}
	return choice;
}

bool wrong(size_t choice, 
	size_t upper, size_t bottom) 
{
	return choice < bottom 
		|| choice > upper 
		|| !std::cin;
}

std::string save_path() 
{
	std::string filename;
	std::cout << "Enter filename: ";
	std::cin.get();
	getline(std::cin, filename);
	return save_folder + filename;
}

void eat_line() 
{
	// cuts symbols in the input stream
	std::cin.clear();
	while (std::cin.get() != '\n')
		continue;
}
