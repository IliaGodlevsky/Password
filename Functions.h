#ifndef FUNCT_H_
#define FUNCT_H_
#include <string>
namespace password
{
	using has_char = bool(*)(const std::string&);
	using settings = void(*)(const char*);
	// 'has' functions
	bool has_letters(const std::string& pass);
	bool has_digits(const std::string& pass);
	bool has_symbols(const std::string& pass);
	bool has_digits_and_letters(const std::string& pass);
	bool has_letters_and_symbols(const std::string& pass);
	bool has_digits_and_symbols(const std::string& pass);
	bool has_symbols_digits_and_letters(const std::string& pass);
	// menu functions
	void length_menu(const char* msg);
	void mode_menu(const char* msg);
	void exapmple_menu(const char* msg);
	void range(int upper, int bottom);
	// input functions
	int set_option(settings menu, int upper, int bottom,const char* msg);
	int input(int upper, int bottom, const char* msg);
	bool wrong(int choice, int upper, int bottom);
	void eat_line();
}
#endif
