#ifndef GEN_H_
#define GEN_H_
#include <string>
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
		std::vector<std::string> passwords;
		std::string generate_symbols();
		std::string create_password(has_char has);
	public:
		Generator(const Options& options);
		friend std::ostream& operator <<
			(std::ostream& os, const Generator& gen);
		void create_passwords();
	};
	void set_options(Options& options);
}
#endif
