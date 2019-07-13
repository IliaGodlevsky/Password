#include "Functions.h"
#include "Generator.h"
int main()
{
	Options options;
	Generator generator;
	do 
		generate(options, generator); 
	while (set_option(menu, YES, NO, ans) + 1);
	system("pause");
}