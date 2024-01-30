#pragma once
#include<cstring>
#include <iostream>
#include <ostream>
#include <iomanip>
#include "Exeption.h"
#include "InputExeption.h"
#include "TextFile.h"
#include "TextFile.cpp"
#include "BinFile.h"
#include "BinFile.cpp"

#define LEN 80
#define MAX_YEAR 2022
#define MIN_YEAR 1900

class Person
{
protected:
	char name[LEN];
	char middle_name[LEN];
	char surname[LEN];
	int birth_year;

public:
	Person()                                                                       //����������� �� ���������
	{
		this->birth_year = 0;
		this->name[0] = '\0';
		this->middle_name[0] = '\0';
		this->surname[0] = '\0';
	}

	Person(int temp, const char* name, const char* middlename, const char* surname) //����������� � �����������
	{
		this->birth_year = temp;
		strcpy_s(this->name, LEN, name);
		strcpy_s(this->middle_name, LEN, middlename);
		strcpy_s(this->surname, LEN, surname);
	}

	Person(const Person& obj)                                                        //����������� �����������
	{
		strcpy_s(this->surname, LEN, obj.surname);
		this->birth_year = obj.birth_year;
		strcpy_s(this->name, LEN, obj.name);
		strcpy_s(this->middle_name, LEN, obj.middle_name);	
	}


	char* get_name();
	char* get_middle_name();
	char* get_surname();
	int get_year();

	void set_name(const char* name);
	void set_middle_name(const char* middlename);
	void set_surname(const char* surname);
	void set_year(int a);

	Person operator=(const Person& obj);                                               //���������� =

	friend istream& operator>>(istream& is, Person& obj);                           
	friend ostream& operator<<(ostream& out, const Person& obj);                 

	friend ofstream& operator<<(ofstream& out, Person& obj);
	friend ifstream& operator>>(ifstream& in, Person& obj);

	friend fstream& operator<<(fstream& in, Person& obj);
	friend fstream& operator>>(fstream& out, Person& obj);

	

	bool operator==(const Person& obj);

	void Find();

	virtual void head_of_sheet();                                                  //����������� ������� ����� �������
};

