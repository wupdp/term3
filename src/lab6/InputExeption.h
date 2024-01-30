#pragma once
#include "Exeption.h"

class InputExeption :public Exeption
{
private:
	char msg[Len];
public:

	InputExeption() :
		Exeption()
	{
		msg[0] = '\0';
	}

	InputExeption(int a, const char* T, const char* M) :
		Exeption(a, T)
	{
		strcpy_s(msg, Len, M);
	}
	~InputExeption() {}

	void show_err() override;
};

int InputInt(int min, int max);
double InputDouble(int min, int max);
char* InputRussian();
char* InputEnglish();

