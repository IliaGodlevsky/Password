#include <algorithm>
#include "Generator.h"
namespace password
{
	Generator::Generator(const Options& options)
		: examples(options.examples),
		mode(options.mode),
		length(options.length){}

	void Generator::remove_duplicates(std::string& word)
	{
		std::sort(word.begin(), word.end());
		auto duplicates = std::unique(word.begin(), word.end());
		word.erase(duplicates, word.end());
	}
	std::string Generator::generate(is_char is)
	{
		std::string word;
		std::string chars = password_symbols();
		char letter;
		unsigned number;
		while (word.size() <= length)
		{
			number = rand() % chars.size();
			letter = chars[number];
			if (is(letter))
				word += letter;
			remove_duplicates(word);
		}
		std::random_shuffle(word.begin(), word.end());
		return word;
	}

	void Generator::create_password(has_char has)
	{
		std::string word;
		
		for (int i = 0; i < examples; i++)
		{
			word = generate(is[mode]);
			while (!has(word))
				word = generate(is[mode]);
			passwords.push_back(word);
		}
	}

	void Generator::in_file(std::ostream& os)
	{
		create_password(has[mode]);
		for (int i = 0; i < examples; i++)
			os << passwords[i] << std::endl;
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