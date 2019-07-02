#include "Generator.h"
Generator::Generator(const Options& opt)
{
	mode = Mode(opt.get_mode());
	length = opt.get_length();
}
std::string Generator::generate(int(*status)(int))
{
	char letter;
	while (word.size() < length)
	{
		letter = char(rand() % CHAR_MAX + 1);
		if (status(int(letter)))
			word += letter;
	}
	return word;
}
std::string Generator::password(bool(*has)(const std::string&))
{
	word = generate(status[mode]);
	while (!has(word))
		word = generate(status[mode]);
	return word;
}
std::string Generator::create_password()
{
	return password(has_symbols[mode]);
}