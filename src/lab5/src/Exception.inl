Exception::Exception(int input_code, std::string input_msg) {
	msg = input_msg;
	code = input_code;
}

Exception::~Exception() {}

void Exception::what() {
	std::cout << "error code " << code << ':' << msg << ", ";
}