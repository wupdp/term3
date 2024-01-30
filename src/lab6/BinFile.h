#pragma once
#include "File.h"

template<class T>
class BinFile :public File
{
public:
	BinFile(string _name = "");
	~BinFile();
	bool is_open();
	bool feof();
	bool open_read_file();
	bool open_write_file();
	void read_file(T& temp);
	void write_file(T& temp);
};
