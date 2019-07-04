#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Functions.h"
#include "Generator.h"
int main()
{
	using namespace std;
	srand(unsigned(time(nullptr)));
	ofstream fout;
	unsigned mode = set_option(mode_menu, MODES, 1);
	unsigned length = set_option(length_menu, MAX_LENGTH, MIN_LENGTH);
	Generator generator(mode, length);
	fout.open(filename);
	generator.in_file(fout, EXAMPLES);
	fout.close();
	system("pause");
}