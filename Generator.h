#ifndef GEN_H_
#define GEN_H_

#include <string>
#include <vector>
#include <iostream>

#include "Constants.h"
#include "Functions.h"

using std::vector;
using std::string;
using std::ostream;

struct Settings { 
	unsigned mode = MIN_MODE;			// mode of generating passwords
	unsigned length = MIN_LENGTH;		// length of generated password
	unsigned examples = EXAMPLES_MIN;	// number of generated examples
};

class Generator {
private:
	Settings settings;
	vector<string> passwords;			// array of generated passwords
	string generate_symbols()const;
	string create_password(has_char has)const;
public:
	Generator() {}
	Generator(const Settings& settings);
	friend ostream& operator << (ostream& os, const Generator& gen);
	Generator& operator=(const Settings& settings);
	void create_passwords();
};

void set_settings(Settings& settings);
void generate(Settings& opt, Generator& gen);
#endif