#include <iostream>
#include <cstring>
#include "Functions.h"
#include "Constants.h"
namespace password
{
	bool has_letters(const std::string& pass)
	{
		return strpbrk(pass.c_str(), letters.c_str()) != nullptr;
	}

	bool has_digits(const std::string& pass)
	{
		return strpbrk(pass.c_str(), digits.c_str()) != nullptr;
	}

	bool has_symbols(const std::string& pass)
	{
		return strpbrk(pass.c_str(), symbols.c_str()) != nullptr;
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

	void length_menu(const char* msg)
	{
		std::cout << msg;
	}

	void mode_menu(const char* msg)
	{
		std::cout << "Modes of generating\n";
		std::cout << "1. only letters\n";
		std::cout << "2. only digits\n";
		std::cout << "3. only symbols\n";
		std::cout << "4. digits and letters\n";
		std::cout << "5. letters and symbols\n";
		std::cout << "6. digits and symbols\n";
		std::cout << "7. symbols, digits and letters\n";
		std::cout << msg;
	}

	void exapmple_menu(const char* msg)
	{
		std::cout << msg;
	}

	void range(int upper, int bottom)
	{
		std::cout << " (" << bottom << " - ";
		std::cout << upper << "): ";
	}
	int set_option(settings menu, int upper, int bottom, const char* msg)
	{
		menu(msg);
		range(upper, bottom);
		return input(upper, bottom, msg);
	}

	int input(int upper, int bottom, const char* msg)
	{
		int choice;
		std::cin >> choice;
		while (wrong(choice, upper, bottom))
		{
			eat_line();
			std::cout << msg;
			std::cin >> choice;
		}
		return choice - 1;
	}

	bool wrong(int choice, int upper, int bottom)
	{
		return choice < bottom || choice > upper ||
			!std::cin;
	}

	void eat_line()
	{
		// cuts symbols in the input stream
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue;
	}
}
