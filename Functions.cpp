#include <iostream>

#include "Functions.h"
#include "Constants.h"

bool has_letters(const Password& pass) 
{ 
	return letters.find_first_of(pass) != NOT_FOUND;
}

bool has_digits(const Password& pass)
{ 
	return digits.find_first_of(pass) != NOT_FOUND;
}

bool has_symbols(const Password& pass)
{ 
	return symbols.find_first_of(pass) != NOT_FOUND;
}

bool has_digits_letters(const Password& pass)
{ 
	return has_digits(pass) && has_letters(pass);
}

bool has_letters_symbols(const Password& pass)
{ 
	return has_letters(pass) && has_symbols(pass);
}

bool has_digits_symbols(const Password& pass)
{ 
	return has_digits(pass) && has_symbols(pass);
}

bool has_symbols_digits_letters(const Password& pass)
{ 
	return has_digits_letters(pass) && has_symbols(pass);
}

void show_modes()
{
	for (unsigned i = 0; i < MODES; i++)
		std::cout << i + 1 << ". "
		<< modes[i] << std::endl;
}

void mode_menu(Message msg)
{
	std::cout << mode_msg_second << std::endl;
	show_modes();
	std::cout << msg;
}

void menu(Message msg) { std::cout << msg; }

void range(unsigned upper, unsigned bottom) 
{
	std::cout << " (" << bottom << " - " << upper << "): ";
}

unsigned set_option(Options menu, 
	Message msg, unsigned upper, unsigned bottom)
{
	menu(msg);
	range(upper, bottom);
	return input(upper, bottom, msg);
}

unsigned input(unsigned upper, 
	unsigned bottom, Message msg)
{
	unsigned choice;
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

bool wrong(unsigned choice, 
	unsigned upper, unsigned bottom) 
{
	return choice < bottom 
		|| choice > upper 
		|| !std::cin;
}

std::string save_path() 
{
	std::string filename;
	std::cout << path_msg;
	std::cin.get();
	getline(std::cin, filename);
	return save_folder + filename;
}

void eat_line() 
{
	// flings away bad input
	std::cin.clear();
	while (!iscntrl(std::cin.get()))
		continue;
}
