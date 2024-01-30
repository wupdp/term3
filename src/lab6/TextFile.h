#pragma once
#include "File.h"

template<class T>
class TextFile :public File
{
public:
	TextFile(string _name);
	~TextFile();
	bool feof();
	bool open_read_file();
	bool open_write_file();
	void read_file(T& temp);
	void write_file(T& temp);
};
