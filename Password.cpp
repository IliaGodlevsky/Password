#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Generator.h"
struct Choice
{
	int mode;
	int length;
};
void menu();
Choice choose();
int choose_mode();
int choose_length();
int main()
{
	using namespace std;
	ofstream fout;
	srand(unsigned(time(nullptr)));
	Choice choice = choose();
	Generator password(choice.mode, choice.length);
	unsigned count = 0;
	fout.open(filename);
	while (count < EXAMPLES)
	{
		fout << password.password();
		fout << std::endl;
		count++;
	}
	fout.close();
}
void menu()
{
	std::cout << "Choose type of password\n";
	std::cout << "1. Only letters\n";
	std::cout << "2. Letters and numbers\n";
	std::cout << "3. Symbols, letters and numbers\n";
}
Choice choose()
{
	menu();
	Choice temp;
	int choice = choose_mode();
	temp.mode = choice;
	choice = choose_length();
	temp.length = choice;
	return temp;
}
int choose_mode()
{
	int choice;
	std::cin >> choice;
	while (choice < 1 || choice > MODES)
		std::cin >> choice;
	return choice - 1;
}
int choose_length()
{
	int choice;
	std::cin >> choice;
	while (choice < 8 || choice > MAX_LENGTH)
		std::cin >> choice;
	return choice;
}