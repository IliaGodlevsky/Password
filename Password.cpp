#include <fstream>
#include "Functions.h"
#include "Generator.h"
int main()
{
	using namespace std;
	Options options;
	set_options(options);
	Generator generator(options);
	generator.create_passwords();
	ofstream fout;
	string filename;
	cout << "Enter filename: ";
	cin >> filename;
	fout.open(filename);
	fout << generator;
	cout << generator;
	fout.close();
	system("pause");
}