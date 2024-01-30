#pragma once
#include "Exeption.h"
#include <iostream>
#include <fstream>
class FileExeption : public Exeption   //����� ���������� �����
{
private:
	char msg[Len];                //��������� �� ������
public:
	FileExeption() :                  //����������� ��-���������
		Exeption()
	{
		msg[0] = '\0';
	}
	//����������� � �����������
	FileExeption(int a, const char* T, const char* M) :
		Exeption(a, T)
	{
		strcpy_s(msg, Len, M);
	}
	~FileExeption() {}                 //����������
	void show_err() override;         //����� ��������� �� ������
};
bool check_file(string name_file);      //������� ��������


