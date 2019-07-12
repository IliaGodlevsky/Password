#include <fstream>
#include "Functions.h"
#include "Generator.h"
int main()
{
	Options options;
	set_options(options);
	Generator generator(options);
	generator.create_passwords();
	std::ofstream fout;
	std::string filename;
	std::cout << "Enter filename: ";
	std::cin >> filename;
	fout.open(filename);
	fout << generator;
	std::cout << generator;
	fout.close();
	system("pause");
}