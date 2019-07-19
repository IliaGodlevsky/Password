#ifndef GEN_H_
#define GEN_H_

#include <iostream>
#include <string>
#include <vector>

#include "Constants.h"
#include "Functions.h"

struct Settings 
{ 
	unsigned mode = MIN_MODE;			// mode of generating passwords
	unsigned length = MIN_LENGTH;		// length of generated password
	unsigned examples = EXAMPLES_MIN;	// number of generated examples
};

class Generator 
{
private:
	Settings settings;
	std::vector<std::string> passwords;	// array of generated passwords
	std::string generate_symbols()const;
	std::string create_password(has_char has)const;
public:
	friend std::ostream& operator << 
		(std::ostream& os, const Generator& gen);
	Generator& operator=(const Settings& settings);
	void create_passwords();
};

void set_settings(Settings& settings);
void generate(Settings& set, Generator& gen);
#endif