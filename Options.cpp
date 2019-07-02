#include "Options.h"
Options::Options()
{
	mode = 0;
	length = MIN_LENGTH;
}
int Options::set_option(void(*menu)(), int upper, int bottom)
{
    menu();
	return input(upper, bottom);
}
void Options::set_mode()
{
	mode = set_option(mode_menu, MODES, 1);
}
void Options::set_length()
{
	length = set_option(length_menu, MAX_LENGTH, MIN_LENGTH);
}