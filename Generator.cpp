#include <algorithm>
#include <random>
#include "Generator.h"
Generator::Generator(const Options& options):
	examples(options.examples),
	mode(options.mode), 
	length(options.length) {}

std::string Generator::generate_symbols()const
{
	std::random_device random;
	std::string word = strings[mode];
	std::shuffle(word.begin(), word.end(), std::mt19937(random()));
	return std::string(word.begin(), word.begin() + length + 1);
}

void Generator::create_passwords()
{
	for (int i = 0; i < examples; i++)
		passwords.push_back(create_password(has[mode]));
}

std::string Generator::create_password(has_char has)const
{
	std::string word = generate_symbols();
	while (!has(word))
		word = generate_symbols();
	return word;
}

std::ostream& operator << (std::ostream& os, const Generator& gen)
{
	for (auto &x : gen.passwords) os << x << std::endl;
	return os;
}

void set_options(Options& options)
{
	options.mode = set_option(mode_menu, MODES, MIN_MODE, mode_msg);
	options.length = set_option(menu, lengths[options.mode], MIN_LENGTH, length_msg);
	options.examples = set_option(menu, EXAMPLES_MAX, EXAMPLES_MIN, example_msg);
}