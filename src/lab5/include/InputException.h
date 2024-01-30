#include "Exception.h"

class InputException : public Exception {
	std::string input_msg;
public:
	InputException(int, std::string, std::string);
	~InputException();
	void what_input();
};

std::string input_str(std::istream& is);
int input_int(std::istream& is, int min, int max);
int input_int(std::istream& is);

#include "../src/InputException.inl"