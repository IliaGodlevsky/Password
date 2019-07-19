#include <algorithm>
#include <random>
#include <fstream>

#include "Generator.h"

std::string Generator::generate_symbols()const 
{
	std::random_device random;
	std::string word = strings[settings.mode - 1];
	std::shuffle(word.begin(), word.end(), std::mt19937(random()));
	return std::string(word.begin(), word.begin() + settings.length);
}

std::string Generator::create_password(has_char has)const 
{
	std::string password = generate_symbols();
	while (!has(password))
		password = generate_symbols();
	return password;
}

void Generator::create_passwords() 
{
	for (unsigned i = 0; i < settings.examples; i++)
		passwords.push_back(create_password(has[settings.mode - 1]));
}

std::ostream& operator << (std::ostream& os, const Generator& gen) 
{
	for (auto &x : gen.passwords) os << x << std::endl;
	return os;
}

Generator& Generator::operator=(const Settings& settings)
{
	this->settings = settings;
	passwords.clear();
	return *this;
}

void set_settings(Settings& settings) 
{
	settings.mode = set_option(mode_menu, 
		mode_msg, MODES, MIN_MODE);
	settings.length = set_option(menu, length_msg, 
		lengths[settings.mode - 1], MIN_LENGTH);
	settings.examples = set_option(menu, 
		example_msg, EXAMPLES_MAX, EXAMPLES_MIN);
}

void generate(Settings& set, Generator& gen)
{
	system("cls");
	std::ofstream fout;
	set_settings(set);
	gen = set;
	gen.create_passwords();
	fout.open(save_path());
	fout << gen;
	std::cout << gen;
	fout.close();
}