#include "Person.h"

char* Person::get_name() { return this->name; };
char* Person::get_middle_name() { return this->middle_name; };
char* Person::get_surname() { return this->surname; };
int Person::get_year() { return this->birth_year; }

void Person::set_name(const char* name) { strcpy_s(this->name, LEN, name); };
void Person::set_middle_name(const char* middlename) { strcpy_s(this->middle_name, LEN, middlename); };
void Person::set_surname(const char* surname) { strcpy_s(this->surname, LEN, surname); };
void Person::set_year(int a) { this->birth_year = a; };

Person Person:: operator=(const Person& obj)
{
	strcpy_s(this->surname, LEN, obj.surname);
	this->birth_year = obj.birth_year;
	strcpy_s(this->name, LEN, obj.name);
	strcpy_s(this->middle_name, LEN, obj.middle_name);
	return *this;
}
bool Person::operator==(const Person& obj)
{

	if (strlen(obj.name))
	{
		if (strncmp(name, obj.name, strlen(obj.name))) return false;
	}

	if (strlen(obj.middle_name))
	{
		if (strncmp(middle_name, obj.middle_name, strlen(obj.middle_name))) return false;
	}

	if (strlen(obj.surname))
	{
		if (strncmp(surname, obj.surname, strlen(obj.surname)))return false;
	}

	if (obj.birth_year != 0)
	{
		if (birth_year != obj.birth_year) return false;
	}

	return true;
}

fstream& operator<<(fstream& in, Person& ob) 
{
	in.write(reinterpret_cast<char*> (&ob.surname), sizeof(ob.surname));
	in.write(reinterpret_cast<char*> (&ob.name), sizeof(ob.name));
	in.write(reinterpret_cast<char*> (&ob.middle_name), sizeof(ob.middle_name));
	in.write(reinterpret_cast<char*> (&ob.birth_year), sizeof(ob.birth_year));
	return in;
}

fstream& operator>>(fstream& out, Person& ob)
{
	out.read(reinterpret_cast<char*> (&ob.surname), sizeof(ob.surname));
	out.read(reinterpret_cast<char*> (&ob.name), sizeof(ob.name));
	out.read(reinterpret_cast<char*> (&ob.middle_name), sizeof(ob.middle_name));
	out.read(reinterpret_cast<char*> (&ob.birth_year), sizeof(ob.birth_year));
	return out;
}

ifstream& operator>>(ifstream& in, Person& ob)
{
	in.ignore(10000, '\n');
	in.getline(ob.surname, 80, '|');
	in.getline(ob.name, 80, '|');
	in.getline(ob.middle_name, 80, '|');
	in >> ob.birth_year;
	return in;
}

istream& operator>>(istream& is, Person& obj)
{
	rewind(stdin);
	std::cout << "�������: ";
	char* tmp = InputRussian();
	strcpy_s(obj.surname, LEN, tmp);
	rewind(stdin);
	std::cout << "���: ";
	tmp = InputRussian();
	strcpy_s(obj.name, LEN, tmp);
	rewind(stdin);
	std::cout << "��������: ";
	tmp = InputRussian();
	strcpy_s(obj.middle_name, LEN, tmp);
	rewind(stdin);
	std::cout << "������� ��� ��������: ";
	obj.birth_year = InputInt(MIN_YEAR, MAX_YEAR);
	delete tmp;
	return is;
}

ostream& operator<<(ostream& out, const Person& obj)
{
	out.setf(ios::left);
	out << setw(15) << obj.surname << setw(15) << obj.name << setw(15) << obj.middle_name << setw(15) << obj.birth_year;
	out.unsetf(ios::left);
	return out;
}


ofstream& operator<<(ofstream& out, Person& obj)
{
	out.setf(ios::left);
	out << setw(15) << obj.surname << '|' << setw(15) << obj.name << '|' << setw(15) << obj.middle_name << '|' << setw(15) << obj.birth_year << '|';
	out.unsetf(ios::left);
	return out;
}

void Person::head_of_sheet()
{
	std::cout.setf(ios::left);
	std::cout << setw(15) << "�������" << setw(15) << "���" << setw(15) << "��������" << setw(15) << "��� ��������" << endl;
	std::cout.unsetf(ios::left);
}

void Person::Find()
{
	int check;
	char* tmp;
	do
	{
		std::cout << "�������� �������� ��� ������" << endl << "1.�������" << endl << "2.���" << endl << "3.��������" << endl << "4.��� ��������" << endl << "5.�����" << endl;

		int a;
		a = InputInt(1, 5);
		switch (a)
		{
		case 1:
		{
			rewind(stdin);
			std::cout << "������� �������: ";
			tmp = InputRussian();
			strcpy_s(this->surname, LEN, tmp);
			std::cout << endl;
			break;
		}
		case 2:
		{
			rewind(stdin);
			std::cout << "������� ���: ";
			tmp = InputRussian();
			strcpy_s(this->name, LEN, tmp);
			std::cout << endl;
			break;
		}
		case 3:
		{
			rewind(stdin);
			std::cout << "������� ��������: ";
			tmp = InputRussian();
			strcpy_s(this->middle_name, LEN, tmp);
			std::cout << endl;
			break;
		}
		case 4:
		{
			rewind(stdin);
			std::cout << "������� ��� ��������: ";
			this->birth_year = InputInt(MIN_YEAR, MAX_YEAR);
			std::cout << endl;
			break;
		}
		case 5:
		{
			return;
		}
		}

		std::cout << "�������� ��������� ��� ������? 1 - ��, 0- ��� : ";

		check = InputInt(0, 1);
		std::cout << endl;

	} while (check == 1);
	return;
}
