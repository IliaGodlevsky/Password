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
struct Options { 
	unsigned mode; 
	unsigned length; 
	unsigned examples; 
};
class Generator {
private:
	unsigned mode = MIN_MODE;			// mode of generating passwords
	unsigned length = MIN_LENGTH;		// length of generated password
	unsigned examples = EXAMPLES_MIN;	// number of generated examples
	vector<string> passwords;			// array of generated passwords
	string generate_symbols()const;
	string create_password(has_char has)const;
public:
	Generator() {}
	Generator(const Options& options);
	Generator& operator=(const Generator& gen) = delete;
	friend ostream& operator << (ostream& os, const Generator& gen);
	void create_passwords();
	void reset_options(const Options& options);
};
void set_options(Options& options);
void generate(Options& opt, Generator& gen);
#endif