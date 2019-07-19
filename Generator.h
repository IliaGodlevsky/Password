#ifndef GEN_H_
#define GEN_H_

#include <iostream>
#include <vector>

#include "Constants.h"
#include "Functions.h"

using Words = std::vector<Word>;

struct Settings 
{ 
	size_t mode;		// mode of generating passwords
	size_t length;		// length of generated password
	size_t examples;	// number of generated examples
};

class Generator 
{
private:
	Settings settings;
	Words words;		// array of generated passwords
	Word generate_symbols()const;
	Word create_word(Control has)const;
public:
	friend std::ostream& operator << 
		(std::ostream& os, const Generator& gen);
	Generator& operator=(const Settings& settings);
	void create_words();
};

void set_settings(Settings& settings);
void generate(Settings& set, Generator& gen);
#endif