#include "Generator.h"

int main()
{
	Settings options;
	Generator generator;
	do 
		generate(options, generator); 
	while (set_option(menu, answer));
	return 0;
}