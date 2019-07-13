#include <iostream>
#include "Functions.h"
#include "Constants.h"

using std::cout;
using std::cin;

bool has_letters(const string& pass) { 
	return letters.find_first_of(pass) != string::npos;
}

bool has_digits(const string& pass) { 
	return digits.find_first_of(pass) != string::npos; 
}

bool has_symbols(const string& pass) { 
	return symbols.find_first_of(pass) != string::npos; 
}

bool has_digits_letters(const string& pass) { 
	return has_digits(pass) && has_letters(pass); 
}

bool has_letters_symbols(const string& pass) { 
	return has_letters(pass) && has_symbols(pass); 
}

bool has_digits_symbols(const string& pass) { 
	return has_digits(pass) && has_symbols(pass); 
}

bool has_symbols_digits_letters(const string& pass) { 
	return has_digits_letters(pass) && has_symbols(pass); 
}

void mode_menu(const char* msg) {
	cout << "Modes of generating\n";
	cout << "1. only letters\n";
	cout << "2. only digits\n";
	cout << "3. only symbols\n";
	cout << "4. digits and letters\n";
	cout << "5. letters and symbols\n";
	cout << "6. digits and symbols\n";
	cout << "7. symbols, digits and letters\n";
	cout << msg;
}

void menu(const char* msg) { cout << msg; }

void range(unsigned upper, unsigned bottom) {
	cout << " (" << bottom << " - ";
	cout << upper << "): ";
}
unsigned set_option(options menu, unsigned upper, unsigned bottom, const char* msg) {
	menu(msg);
	range(upper, bottom);
	return input(upper, bottom, msg);
}

unsigned input(unsigned upper, unsigned bottom, const char* msg) {
	unsigned choice;
	cin >> choice;
	while (wrong(choice, upper, bottom))
	{
		eat_line();
		cout << msg;
		range(upper, bottom);
		cin >> choice;
	}
	return choice - 1;
}

bool wrong(unsigned choice, unsigned upper, unsigned bottom) {
	return choice < bottom || choice > upper || !cin;
}

string save_path()
{
	string filename;
	cout << "Enter filename: ";
	cin >> filename;
	return save_folder + filename;
}

void eat_line() {
	// cuts symbols in the input stream
	cin.clear();
	while (cin.get() != '\n')
		continue;
}
