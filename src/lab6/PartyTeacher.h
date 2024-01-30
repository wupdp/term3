#pragma once
#include "Teacher.h"
#include "Partymember.h"

class PartyTeacher : public Teacher, public PartyMember
{
protected:
	double contributions;

public:

	PartyTeacher() :                                //����������� �� ���������
		Teacher(), PartyMember()
	{
		this->contributions = 0;
	}

	PartyTeacher(double contrib, int yearofbirth, const char* name, const char* midname, const char* surname, const char* ocup, const char* spec, const char** work, const char* nameoforg, const char** autobio, int yearofenter) :
		Teacher(yearofbirth, name, midname, surname, ocup, spec, work), PartyMember(yearofbirth, name, midname, surname, nameoforg, yearofenter, autobio),
		Person(yearofbirth, name, midname, surname)  //����������� � �����������
	{
		this->contributions = contrib;
	}

	~PartyTeacher()                                 //����������
	{
	}

	PartyTeacher(PartyTeacher& obj) : Teacher(obj), PartyMember(obj),Person(obj)                  //����������� �����������
	{
		this->contributions = obj.contributions;
	}

	double get_contributions();
	void set_contributions(int temp);

	PartyTeacher operator=(PartyTeacher& obj);                         //���������� =

	friend istream& operator>>(istream& is, PartyTeacher& obj);      //���������� �����

	friend ostream& operator<<(ostream& out, const PartyTeacher& obj);     //���������� ������

	friend ofstream& operator<<(ofstream& out, PartyTeacher& obj);
	friend ifstream& operator>>(ifstream& in, PartyTeacher& obj);

	friend fstream& operator<<(fstream& in, PartyTeacher& obj);
	friend fstream& operator>>(fstream& out, PartyTeacher& obj);

	bool operator==(const PartyTeacher& obj);

	void head_of_sheet() override;                                   //����� �������

	void Find();

	//void menu() override;
};