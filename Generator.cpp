#include <algorithm>
#include "Generator.h"
namespace password
{
	Generator::Generator(const Options& options)
		: examples(options.examples),
		mode(options.mode),
		length(options.length){}

	std::string Generator::generate_symbols(is_char is)
	{
		std::string word = strings[mode];
		std::random_shuffle(word.begin(), word.end());
		std::string password(word.begin(), word.begin() + length + 1);
		std::random_shuffle(password.begin(), password.end());
		return password;
	}
	void Generator::create_passwords()
	{
		for (int i = 0; i < examples; i++)
			passwords.push_back(create_password(has[mode]));
	}

	std::string Generator::create_password(has_char has)
	{
		std::string word;
		for (int i = 0; i < examples; i++)
		{
			word = generate_symbols(is[mode]);
			while (!has(word))
				word = generate_symbols(is[mode]);
		}
		return word;
	}

	std::ostream& operator << (std::ostream& os, const Generator& gen)
	{
		for (int i = 0; i < gen.examples; i++)
			os << gen.passwords[i] << std::endl;
		return os;
	}

	void set_options(Options& options)
	{
		options.mode = set_option(mode_menu, MODES, 1, "Choose mode");
		options.length = set_option(length_menu, lengths[options.mode], 
			MIN_LENGTH, "Enter length of the password: ");
		options.examples = set_option(exapmple_menu, EXAMPLES_MAX, 
			EXAMPLES_MIN, "Enter number of examples of password: ");
	}
}