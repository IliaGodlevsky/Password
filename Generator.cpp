#include <algorithm>
#include "Generator.h"
int isdotorcomma(int symbol)
{
	return symbol == '.' || symbol == ','
		|| symbol == '`';
}
int issymbol(int symbol)
{
	return (isalnum(symbol) || ispunct(symbol))
		&& !isdotorcomma(symbol);
}
bool has_numbers(const std::string& pass)
{
	return strpbrk(pass.c_str(), numbers) != nullptr;
}
bool has_symbols_and_numbers(const std::string& pass)
{
	return	has_letters(pass) &&
		has_numbers(pass) &&
		strpbrk(pass.c_str(), symbols) != nullptr;
}
std::string password_symbols()
{
	const char* chars[4] = { 
		upper_letters,
		lower_letters,
		numbers, 
		symbols };
	std::string word;
	for (int i = 0; i < 4; i++)
		word += chars[i];
	return word;
}
Generator::Generator(int mode, int length)
{
	this->mode = Mode(mode);
	this->length = length;
}
std::string Generator::generate(int(*status)(int))
{
	std::string word;
	std::string chars = password_symbols();
	std::random_shuffle(chars.begin(), chars.end());
	char letter;
	int number;
	while (word.size() <= length)
	{
		number = rand() % chars.size();
		letter = chars[number];
		if (status(int(letter)))
			word += letter;
	}
	return word;
}
std::string Generator::password(bool(*has)(const std::string&))
{
	std::string word;
	word = generate(status[mode]);
	while (!has(word))
		word = generate(status[mode]);
	std::random_shuffle(word.begin(), word.end());
	return word;
}
std::string Generator::create_password()
{
	return password(has_symbols[mode]);
}