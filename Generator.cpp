#include <algorithm>
#include <random>
#include "Generator.h"
Generator::Generator(const Options& options):
	examples(options.examples),
	mode(options.mode), 
	length(options.length) {}

string Generator::generate_symbols()const {
	std::random_device random;
	string word = strings[mode];
	std::shuffle(word.begin(), word.end(), std::mt19937(random()));
	return string(word.begin(), word.begin() + length + 1);
}

string Generator::create_password(has_char has)const {
	string password = generate_symbols();
	// if password doesn't have some symbols
	// that have been chosen, generating repeats
	while (!has(password))
		password = generate_symbols();
	return password;
}

void Generator::create_passwords() {
	for (unsigned i = 0; i < examples; i++)
		passwords.push_back(create_password(has[mode]));
}

ostream& operator << (ostream& os, const Generator& gen) {
	for (auto &x : gen.passwords) os << x << std::endl;
	return os;
}

void set_options(Options& options) {
	options.mode = set_option(mode_menu, MODES, MIN_MODE, mode_msg);
	options.length = set_option(menu, lengths[options.mode], MIN_LENGTH, length_msg);
	options.examples = set_option(menu, EXAMPLES_MAX, EXAMPLES_MIN, example_msg);
}