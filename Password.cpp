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
	generator.create_passwords();
	fout.open(filename);
	cout << generator;
	fout << generator;
	fout.close();
	system("pause");
}