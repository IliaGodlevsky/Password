#include <algorithm>
#include <random>
#include <fstream>
#include "Generator.h"
using std::cout;
using std::cin;
using std::ofstream;
Generator::Generator(const Settings& settings) :
	settings(settings) {}

string Generator::generate_symbols()const {
	std::random_device random;
	string word = strings[settings.mode];
	std::shuffle(word.begin(), word.end(), std::mt19937(random()));
	return string(word.begin(), word.begin() + settings.length + 1);
}

string Generator::create_password(has_char has)const {
	string password = generate_symbols();
	while (!has(password))
		password = generate_symbols();
	return password;
}

void Generator::create_passwords() {
	for (unsigned i = 0; i < settings.examples; i++)
		passwords.push_back(create_password(has[settings.mode]));
}

ostream& operator << (ostream& os, const Generator& gen) {
	for (auto &x : gen.passwords) os << x << std::endl;
	return os;
}

Generator&::Generator::operator=(const Settings& settings)
{
	this->settings.mode = settings.mode;
	this->settings.length = settings.length;
	this->settings.examples = settings.examples;
	passwords.clear();
	return *this;
}

void set_settings(Settings& settings) {
	settings.mode = set_option(mode_menu, MODES, MIN_MODE, mode_msg);
	settings.length = set_option(menu, lengths[settings.mode], MIN_LENGTH, length_msg);
	settings.examples = set_option(menu, EXAMPLES_MAX, EXAMPLES_MIN, example_msg);
}

void generate(Settings& set, Generator& gen){
	ofstream fout;
	system("cls");
	set_settings(set);
	gen = set;
	gen.create_passwords();
	fout.open(save_path());
	fout << gen;
	cout << gen;
	fout.close();
}