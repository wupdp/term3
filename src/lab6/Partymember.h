#pragma once
#include "Person.h"
class PartyMember :
	virtual public Person
{
protected:
	char org_name[LEN];
	int enter_year;
	char biography[3][LEN];
public:

	PartyMember() :                                        //���������� �� ���������
		Person()
	{
		this->org_name[0] = '\0';
		this->enter_year = 0;
		for (int i = 0; i < 3; i++)
		{
			this->biography[i][0] = '\0';
		}
	}

	PartyMember(int yearofbirth, const char* name, const char* middlename, const char* surname, const char* nameoforg, int yearofenter, const char** autob) :
		Person(yearofbirth, name, middlename, surname)        //����������� � �����������
	{
		strcpy_s(this->org_name, LEN, nameoforg);
		this->enter_year = yearofenter;
		for (int i = 0; i < 3; i++)
		{
			strcpy_s(this->biography[i], LEN, autob[i]);
		}
	}
	~PartyMember()                                         //����������
	{
	}

	PartyMember(PartyMember& obj) : Person(obj)                         //����������� �����������
	{
		strcpy_s(this->org_name, LEN, obj.org_name);
		this->enter_year = obj.enter_year;
		for (int i = 0; i < 3; i++)
		{
			strcpy_s(this->biography[i], LEN, obj.biography[i]);
		}
	}

	char* get_org_name();
	int get_enter_year();
	char** get_biography();

	void set_org_name(char* a);
	void set_enter_year(int a);
	void set_biography(char** a);

	PartyMember operator=(const PartyMember& obj);               //���������� =

	friend istream& operator>>(istream& is, PartyMember& obj);   //���������� �����

	friend ostream& operator<<(ostream& out, const PartyMember& obj);  //���������� ������

	friend ofstream& operator<<(ofstream& out, PartyMember& obj);
	friend ifstream& operator>>(ifstream& in, PartyMember& obj);

	friend fstream& operator<<(fstream& in, PartyMember& obj);
	friend fstream& operator>>(fstream& out, PartyMember& obj);

	bool operator==(const PartyMember& obj);

	void head_of_sheet() override;                                 //����� �������

	void Find();
};

