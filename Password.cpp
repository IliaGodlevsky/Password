#include <ctime>
#include "Generator.h"
int main()
{
	srand(unsigned(time(nullptr)));
	Settings options;
	Generator generator;
	do 
		generate(options, generator);
	while (set_option(menu, answer));
}