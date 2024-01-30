#include <iostream>

#pragma once
class Exception {
	std::string msg;
	int code;
public:
	Exception(int code, std::string msg);
	virtual ~Exception();
	void what();
};

#include "../src/Exception.inl"
