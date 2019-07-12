#ifndef GEN_H_
#define GEN_H_
#include <string>
#include <vector>
#include <iostream>
#include "Constants.h"
#include "Functions.h"
// structure for generating options
struct Options { 
	unsigned mode; 
	unsigned length; 
	unsigned examples; 
};
class Generator {
private:
	unsigned mode;						// mode of generating passwords
	unsigned length;					// length of generated password
	const unsigned examples;			// number of generated examples
	std::vector<std::string> passwords;	// array of generated passwords
	std::string generate_symbols()const;
	std::string create_password(has_char has)const;
public:
	Generator(const Options& options);
	Generator() = delete;
	Generator(const Generator& gen) = delete;
	Generator& operator=(const Generator& gen) = delete;
	friend std::ostream& operator <<
		(std::ostream& os, const Generator& gen);
	void create_passwords();
};
void set_options(Options& options);
#endif