#include <algorithm>
#include <random>
#include <fstream>

#include "Generator.h"

Word Generator::generate_symbols()const 
{
	std::random_device random;
	Word word = strings[settings.mode - 1];
	std::shuffle(word.begin(), word.end(), std::mt19937(random()));
	return Word(word.begin(), word.begin() + settings.length);
}

Word Generator::create_word(Control control)const 
{
	Word word = generate_symbols();
	while (!control(word))
		word = generate_symbols();
	return word;
}

void Generator::create_words() 
{
	for (size_t i = 0; i < settings.examples; i++)
		words.push_back(create_word(control[settings.mode - 1]));
}

std::ostream& operator << (std::ostream& os, const Generator& gen) 
{
	for (auto &x : gen.words) os << x << std::endl;
	return os;
}

Generator& Generator::operator=(const Settings& settings)
{
	this->settings = settings;
	words.clear();
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
	gen.create_words();
	fout.open(save_path());
	fout << gen;
	std::cout << gen;
	fout.close();
}