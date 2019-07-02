#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Functions.h"
#include "Options.h"
#include "Constants.h"
#include "Generator.h"
int main()
{
	using namespace std;
	ofstream fout;
	fout.open(filename);
	Options options;
	options.set_mode();
	options.set_length();
	Generator generator(options);
	in_file(fout, generator);
	fout.close();
	system("pause");
}