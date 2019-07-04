#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Options.h"
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
	generator.in_file(cout, EXAMPLES);
	fout.close();
	system("pause");
}