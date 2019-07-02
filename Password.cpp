#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Constants.h"
#include "Generator.h"
#include "Options.h"
void in_file(std::ostream& os, Generator& gen);
int main()
{
	using namespace std;
	srand(unsigned(time(nullptr)));
	ofstream fout;
	Options options;
	options.set_mode();
	options.set_length();
	int mode = options.get_mode();
	int length = options.get_length();
	Generator generator(mode, length);
	fout.open(filename);
	in_file(fout, generator);
	fout.close();
	system("pause");
}
void in_file(std::ostream& os, Generator& gen)
{
	std::string password;
	int count = 0;
	while (count < EXAMPLES)
	{
		password = gen.create_password();
		os << password;
		os << std::endl;
		count++;
	}
}