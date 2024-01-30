#pragma once


#include "Person.h"
class Teacher :
	virtual public Person
{

protected:
	char occupation[LEN];
	char specialization[LEN];
	char scienceWork[3][LEN];

public:

	Teacher() :                                           //����������� �� ���������
		Person()
	{
		this->occupation[0] = '\0';
		this->specialization[0] = '\0';
		for (int i = 0; i < 3; i++)
		{
			this->scienceWork[i][0] = '\0';
		}
	}

	Teacher(int yearofbirth, const char* name, const char* middlename, const char* surname, const char* occup, const char* spec, const char** work) :
		Person(yearofbirth, name, middlename, surname)        //����������� � �����������
	{
		strcpy_s(this->occupation, LEN, occup);
		strcpy_s(this->specialization, LEN, spec);
		for (int i = 0; i < 3; i++)
		{
			strcpy_s(this->scienceWork[i], LEN, work[i]);
		}
	}
	~Teacher()                                            //����������
	{
	}

	Teacher(Teacher& obj) :Person(obj)                              //����������� �����������
	{
		strcpy_s(this->occupation, LEN, obj.occupation);
		strcpy_s(this->specialization, LEN, obj.specialization);
		for (int i = 0; i < 3; i++)
		{
			strcpy_s(this->scienceWork[i], LEN, obj.scienceWork[i]);
		}
	}

	char* get_occupation();
	char* get_specialization();
	char** getScienceWork();

	void set_occupation(char* a);
	void set_specialization(char* a);
	void set_scienceWork(char** a);

	Teacher operator=(const Teacher& obj);                //���������� =

	friend istream& operator>>(istream& is, Teacher& obj);  //���������� �����

	friend ostream& operator<<(ostream& out, const Teacher& obj); //���������� ������

	friend ofstream& operator<<(ofstream& out, Teacher& obj);
	friend ifstream& operator>>(ifstream& in, Teacher& obj);

	friend fstream& operator<<(fstream& in, Teacher& obj);
	friend fstream& operator>>(fstream& out, Teacher& obj);

	bool operator==(const Teacher& obj);

	void Find();

	//void menu() override;

	void head_of_sheet() override;
};

