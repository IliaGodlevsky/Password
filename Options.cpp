#include "Options.h"
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
Options::Options()
{
	mode = 0;
	length = MIN_LENGTH;
}
int Options::set_option(void(*menu)(), int upper, int bottom)
{
    menu();
	return input(upper, bottom);
}
void Options::set_mode()
{
	mode = set_option(mode_menu, MODES, 1);
}
void Options::set_length()
{
	length = set_option(length_menu, MAX_LENGTH, MIN_LENGTH);
}