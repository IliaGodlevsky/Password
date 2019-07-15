#include <algorithm>
#include <random>
#include <fstream>

#include "Generator.h"

using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::random_device;
using std::mt19937;
using std::shuffle;

string Generator::generate_symbols()const {
	random_device random;
	string word = strings[settings.mode - 1];
	shuffle(word.begin(), word.end(), mt19937(random()));
	return string(word.begin(), word.begin() + settings.length);
}

string Generator::create_password(has_char has)const {
	string password = generate_symbols();
	while (!has(password))
		password = generate_symbols();
	return password;
}

void Generator::create_passwords() {
	for (unsigned i = 0; i < settings.examples; i++)
		passwords.push_back(create_password(has[settings.mode - 1]));
}

ostream& operator << (ostream& os, const Generator& gen) {
	for (auto &x : gen.passwords) os << x << endl;
	return os;
}

Generator&::Generator::operator=(const Settings& settings)
{
	this->settings = settings;
	passwords.clear();
	return *this;
}

void set_settings(Settings& settings) {
	settings.mode = set_option(mode_menu, 
		mode_msg, MODES, MIN_MODE);
	settings.length = set_option(menu, length_msg, 
		lengths[settings.mode - 1], MIN_LENGTH);
	settings.examples = set_option(menu, 
		example_msg, EXAMPLES_MAX, EXAMPLES_MIN);
}

void generate(Settings& set, Generator& gen){
	system("cls");
	ofstream fout;
	set_settings(set);
	gen = set;
	gen.create_passwords();
	fout.open(save_path());
	fout << gen;
	cout << gen;
	fout.close();
}