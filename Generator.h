#ifndef GEN_H_
#define GEN_H_

#include <iostream>
#include <vector>

#include "Constants.h"

typedef std::vector<Password> Passwords;

struct Settings 
{ 
	unsigned mode;			// mode of generating passwords
	unsigned length;		// length of generated password
	unsigned examples;		// number of generated examples
};

class Generator 
{
private:
	Settings settings;
	Passwords passwords;	// array of generated passwords
	Password generate_symbols()const;
	Password create_password(Check check)const;
public:
	friend std::ostream& operator << 
		(std::ostream& os, const Generator& gen);
	Generator& operator=(const Settings& settings);
	void create_passwords();
};

void set_settings(Settings& settings);
void generate(Settings& set, Generator& gen);
#endif