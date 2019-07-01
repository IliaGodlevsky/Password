#include "Generator.h"
int isdotorcomma(int symbol)
{
	return symbol == '.' || symbol == ',';
}
int issymbol(int symbol)
{
	return (isalnum(symbol) || ispunct(symbol))
		&& !isdotorcomma(symbol);
}
std::string Generator::generate(isfunct status)
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