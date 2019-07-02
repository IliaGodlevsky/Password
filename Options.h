#ifndef OPTIONS_H_
#define OPTIONS_H_
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
	int get_mode()const { return mode; }
	int get_length()const { return length; }
};
#endif