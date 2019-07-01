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
std::string Generator::generate(isfunct status)const
{
	std::string password;
	char letter;
	while (password.size() < length)
	{
		letter = char(rand() % CHAR_MAX + 1);
		if (status(int(letter)))
			password += letter;
	}
	return password;
}