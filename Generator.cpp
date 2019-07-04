#include <algorithm>
#include "Generator.h"
Generator::Generator(int mode, int length)
{
	this->mode = mode;
	this->length = length;
}
std::string Generator::generate(is_char is)
{
	std::string word;
	std::string chars = password_symbols();
	char letter;
	int number;
	while (word.size() <= length)
	{
		number = rand() % chars.size();
		letter = chars[number];
		if (is(letter))
			word += letter;
	}
	return word;
}
std::string Generator::password(has_char has)
{
	std::string word;
	word = generate(status[mode]);
	while (!has(word))
		word = generate(status[mode]);
	return word;
}
std::string Generator::create_password()
{
	return password(has[mode]);
}
void Generator::in_file(std::ostream& os, int examples)
{
	for (int i = 0; i < examples; i++)
		os << create_password() << std::endl;
}