#ifndef OPT_H_
#define OPT_H_
#include "Constants.h"
#include "Generator.h"
bool wrong(int choice, int upper, int bottom);
int input(int upper, int bottom);
void length_menu();
void mode_menu();
void eat_line();
class Options
{
private:
	unsigned int mode;
	unsigned int length;
    int set_option(void(*menu)(), int upper, int bottom);
public:
	Options();
    Options(const Options& op) = delete;
    void set_mode();
    void set_length();
	unsigned int get_mode()const { return mode; }
	unsigned int get_length()const { return length; }
};
#endif