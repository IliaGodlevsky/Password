#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Functions.h"
#include "Generator.h"
int main()
{
	using namespace std;
	using namespace password;
	cout << "Password generator\n";
	srand(unsigned(time(nullptr)));
	ofstream fout;
	Options options;
	set_options(options);
	Generator generator(options);
	fout.open(filename);
	generator.in_file(cout);
	generator.in_file(fout);
	fout.close();
	system("pause");
}