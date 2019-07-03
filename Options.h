#ifndef OPT_H_
#define OPT_H_
#include "Constants.h"
#include "Generator.h"
class Options
{
private:
	int mode;
	int length;
    int set_option(void(*menu)(), int upper, int bottom);
public:
	Options();
    void set_mode();
    void set_length();
	int get_mode()const { return mode; }
	int get_length()const { return length; }
};
#endif