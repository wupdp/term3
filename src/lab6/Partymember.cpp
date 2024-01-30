#include "Partymember.h"


char* PartyMember::get_org_name() { return org_name; }
int PartyMember::get_enter_year() { return enter_year; }
char** PartyMember::get_biography() { return (char**)biography; }

void PartyMember::set_org_name(char* a) { strcpy_s(this->org_name, LEN, a); }
void PartyMember::set_enter_year(int a) { this->enter_year = a; }
void PartyMember::set_biography(char** a)
{
	for (int i = 0; i < 3; i++)
	{
		strcpy_s(this->biography[i], LEN, a[i]);
	}
}

bool PartyMember:: operator==(const PartyMember& obj)
{
	if (!(*((Person*)this) == (Person&)obj)) return false;
	
	if (strlen(obj.org_name))
	{
		if (strncmp(org_name, obj.org_name,strlen(obj.org_name)))return false;
	}

	if (obj.enter_year != 0)
	{
		if (enter_year != obj.enter_year) return false;
	}

	for (int i = 0; i < 3; i++)
	{
		if (strlen(obj.biography[i]))
		{
			if (strncmp(biography[i], obj.biography[i],strlen(obj.biography[i])))return false;
		}
	}

	return true;
}

PartyMember PartyMember:: operator=(const PartyMember& obj)
{
	*((Person*)this) = (Person&)obj;
	this->enter_year = obj.enter_year;
	strcpy_s(this->org_name, LEN, obj.org_name);
	for (int i = 0; i < 3; i++)
	{
		strcpy_s(this->biography[i], LEN, obj.biography[i]);
	}
	return *this;
}

fstream& operator<<(fstream& in, PartyMember& ob)
{
	in << dynamic_cast<Person&>(ob);
	in.write(reinterpret_cast<char*> (&ob.org_name), sizeof(ob.org_name));
	in.write(reinterpret_cast<char*> (&ob.enter_year), sizeof(ob.enter_year));
	for (int i = 0; i < 3; i++)
	{
		in.write(reinterpret_cast<char*> (&ob.biography[i]), sizeof(ob.biography[i]));
	}

	return in;
}

fstream& operator>>(fstream& out, PartyMember& ob)
{
	out >> dynamic_cast<Person&>(ob);
	out.read(reinterpret_cast<char*> (&ob.org_name), sizeof(ob.org_name));
	out.read(reinterpret_cast<char*> (&ob.enter_year), sizeof(ob.enter_year));
	for (int i = 0; i < 3; i++)
	{
		out.read(reinterpret_cast<char*> (&ob.biography[i]), sizeof(ob.biography[i]));
	}
	return out;
}

istream& operator>>(istream& is, PartyMember& obj)
{
	rewind(stdin);
	is >> dynamic_cast<Person&>(obj);
	std::cout << "������� �������� �����������: ";
	rewind(stdin);
	char* tmp = InputRussian();
	strcpy_s(obj.org_name, LEN, tmp);
	std::cout << "������� ��� ����������: ";
	rewind(stdin);
	obj.enter_year = InputInt(MIN_YEAR, MAX_YEAR);
	std::cout << "������� �������������: ";
	for (int i = 0; i < 3; i++)
	{
		rewind(stdin);
		tmp = InputRussian();
		strcpy_s(obj.biography[i], LEN, tmp);
	}
	delete tmp;
	return is;
}
ifstream& operator>>(ifstream& in, PartyMember& obj)
{
	in >> dynamic_cast<Person&>(obj);
	in.ignore(80, '|');
	in.getline(obj.org_name, 80, '|');
	//in.clear();
	in >> obj.enter_year;
	in.ignore(80, '|');
	for (int i = 0; i < 3; i++)
	{
		if (i != 0) in.ignore(1000000, '|');
		in.getline(obj.biography[i], 80, '|');
		//if (i != 2)in.clear();
	}
	return in;
}
ostream& operator<<(ostream& out, const PartyMember& obj)
{

	out << static_cast<const Person&>(obj);
	out.setf(ios::left);
	out << setw(20) << obj.org_name << setw(20) << obj.enter_year;
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			out << setw(20) << obj.biography[i] << setw(20) << endl;
			continue;
		}
		out << setw(105) << " "  << obj.biography[i] << setw(20) << endl;
	}
	out.unsetf(ios::left);
	return out;
}

ofstream& operator<<(ofstream& out, PartyMember& obj)
{
	out << dynamic_cast<Person&>(obj);
	out.setf(ios::left);
	out << setw(20) << obj.org_name << '|' << setw(20) << obj.enter_year << '|';
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			out << setw(20) << obj.biography[i] << '|' << setw(20) << endl;
			continue;
		}
		out << setw(105) << " "<<"|" << obj.biography[i] << '|' << setw(20) << endl;
	}
	out.unsetf(ios::left);
	return out;
}

void PartyMember::head_of_sheet()
{

	std::cout.setf(ios::left);
	std::cout << setw(5) << "�" << setw(15) << "�������" << setw(15) << "���" << setw(15) << "��������" << setw(15) << "��� ��������";
	std::cout << setw(15) << "����.�����." << setw(15) << "��� ����������" << setw(15) << "�������������" << endl;
	std::cout.unsetf(ios::left);
}

void PartyMember::Find()
{

	int check;
	char* tmp;
	do
	{
		rewind(stdin);
		cout << "�������� �������� ��� ������" << endl << "1.�������" << endl << "2.���" << endl << "3.��������" << endl << "4.��� ��������" << endl;
		cout << "5.�������� �����������" << endl << "6.��� ����������" << endl << "7.�������������" << endl << "8. �����" << endl;
		int a;
		a = InputInt(1, 8);
		switch (a)
		{
		case 1:
		{
			rewind(stdin);
			std::cout << "������� �������: ";
			tmp = InputRussian();
			strcpy_s(this->Surname, LEN, tmp);
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
			strcpy_s(this->MiddleName, LEN, tmp);
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
			rewind(stdin);
			std::cout << "������� �������� �����������: ";
			tmp = InputRussian();
			strcpy_s(this->org_name, LEN, tmp);
			cout << endl;
			break;
		}
		case 6:
		{
			std::cout << "������� ��� ����������: ";
			this->enter_year = InputInt(MIN_YEAR, MAX_YEAR);
			cout << endl;
			break;
		}
		case 7:
		{
			std::cout << "������� �������������: ";
			for (int i = 0; i < 3; i++)
			{
				rewind(stdin);
				tmp = InputRussian();
				strcpy_s(this->biography[i], LEN, tmp);
			}
			break;
		}
		case 8:
		{
			return;
		}
		}

		std::cout << "�������� ��������� ��� ������? 1 - ��, 0 - ���";

		check = InputInt(0, 1);
		std::cout << endl;

	} while (check == 1);

	return;
}

