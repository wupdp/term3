#pragma once
#include <fstream>
#include "Exception.h"

class FileException : public Exception {
	std::string file_msg;
public:
	FileException(int, std::string, std::string);
	~FileException();
	void what_file();
};

void check_file_exist(const char* filename);
void check_file_empty(const char* filename);
void check_file_open(const char* filename);

#include "../src/FileException.inl"