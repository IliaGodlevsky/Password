#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include "Functions.h"

typedef const std::string Blank;

static constexpr unsigned NOT_FOUND = Blank::npos;
// messages for functions
static Message path_msg = "Enter filename: ";
static Message answer = "One more";
static Message mode_msg_first = "Choose mode";
static Message mode_msg_second = "Modes of generating";
static Message length_msg = "Enter length of the password";
static Message example_msg = "Enter number of examples";
static Message save_folder = "Save/";
// blanks for passwords
static Blank lower_letters = "abcdefghijklmnopqrstuvwxyz";
static Blank upper_letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static Blank letters = lower_letters + upper_letters;
static Blank symbols = "!#$%&'()*+,-.:;<=>?@[]^_`{|}~";
static Blank digits = "0123456789";

enum 
{
	MIN_LENGTH = 3,
	MIN_MODE = 1,
	MODES = 7,
	EXAMPLES_MAX = 50,
	EXAMPLES_MIN = 10
};

static Blank strings[MODES]
{
	letters,
	digits,
	symbols,
	digits + letters,
	letters + symbols, 
	digits + symbols,
	digits + letters + symbols
};

static const unsigned lengths[MODES] 
{
	letters.size(),
	digits.size(),
	symbols.size(),
	digits.size() + letters.size(),
	letters.size() + symbols.size(),
	digits.size() + symbols.size(),
	letters.size() + symbols.size() + digits.size()
};

static const Check check[MODES]
{
	has_letters,
	has_digits,
	has_symbols,
	has_digits_letters,
	has_letters_symbols,
	has_digits_symbols,
	has_symbols_digits_letters
};

static Message modes[MODES]
{
	"letters","digits","symbols","digits and letters",
	"letters and symbols", "digits and symbols",
	"symbols, digits and letters"
};
#endif
