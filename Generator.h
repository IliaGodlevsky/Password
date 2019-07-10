#ifndef GEN_H_
#define GEN_H_
#include <string>
#include <cctype>
#include <vector>
#include <iostream>
#include "Constants.h"
#include "Functions.h"
namespace password
{
	struct Options
	{
		int mode;
		unsigned length;
		int examples;
	};
	class Generator
	{
	private:
		int mode;
		unsigned length;
		const int examples;
		std::string generate(is_char is);
		void create_password(has_char has);
		std::vector<std::string> passwords;
		void remove_duplicates(std::string& word);
	public:
		Generator(const Options& options);
		void in_file(std::ostream& os);
	};
	void set_options(Options& options);
}
#endif