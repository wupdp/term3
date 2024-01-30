#include "Teacher.h"

char* Teacher::get_occupation() { return this->occupation; }
char* Teacher::get_specialization() { return this->specialization; }
char** Teacher::getScienceWork() { return (char**)this->scienceWork; }

void Teacher::set_occupation(char* a) { strcpy_s((this->occupation), LEN, a); }
void Teacher::set_specialization(char* a) { strcpy_s((this->specialization), LEN, a); }
void Teacher::set_scienceWork(char** a)
{
	for (int i = 0; i < 3; i++)
		strcpy_s(this->scienceWork[i], LEN, a[i]);
}

bool Teacher:: operator==(const Teacher& obj)
{
	if (!(*((Person*)this) == (Person&)obj)) return false;
	
	if (strlen(obj.occupation))
	{
		if (strncmp(occupation, obj.occupation,strlen(obj.occupation))) return false;
	}

	if (strlen(obj.specialization))
	{
		if (strncmp(specialization, obj.specialization,strlen(obj.specialization))) return false;
	}

	for (int i = 0; i < 3; i++)
	{
		if (strlen(obj.scienceWork[i]))
		{
			if (strncmp(scienceWork[i], obj.scienceWork[i],strlen(obj.scienceWork[i])))return false;
		}
	}
	return true;
}

Teacher Teacher::operator=(const Teacher& obj)
{
	*((Person*)this) = (Person&)obj;
	strcpy_s(this->occupation, LEN, obj.occupation);

	strcpy_s(this->specialization, LEN, obj.specialization);
	for (int i = 0; i < 3; i++)
	{
		strcpy_s(this->scienceWork[i], LEN, obj.scienceWork[i]);
	}
	return *this;
}

fstream& operator<<(fstream& in, Teacher& ob)
{
	in << dynamic_cast<Person&>(ob);

	in.write(reinterpret_cast<char*> (&ob.occupation), sizeof(ob.occupation));
	in.write(reinterpret_cast<char*> (&ob.specialization), sizeof(ob.specialization));
	for (int i = 0; i < 3; i++)
	{
		in.write(reinterpret_cast<char*> (&ob.scienceWork[i]), sizeof(ob.scienceWork[i]));
	}
	return in;
}

fstream& operator>>(fstream& out, Teacher& ob)
{
	out >> dynamic_cast<Person&>(ob);
	out.read(reinterpret_cast<char*> (&ob.occupation), sizeof(ob.occupation));
	out.read(reinterpret_cast<char*> (&ob.specialization), sizeof(ob.specialization));
	for (int i = 0; i < 3; i++)
	{
		out.read(reinterpret_cast<char*> (&ob.scienceWork[i]), sizeof(ob.scienceWork[i]));
	}
	return out;
}

istream& operator>>(istream& is, Teacher& obj)
{
	rewind(stdin);
	is >> dynamic_cast<Person&>(obj);
	std::cout << "������� ���������: ";
	rewind(stdin);
	char* tmp = InputRussian();
	strcpy_s(obj.occupation, LEN, tmp);

	std::cout << "������� �������������: ";
	rewind(stdin);
	tmp = InputRussian();
	strcpy_s(obj.specialization, LEN, tmp);

	std::cout << "������� ������� ������: ";
	for (int i = 0; i < 3; i++)
	{
		rewind(stdin);
		tmp = InputRussian();
		strcpy_s(obj.scienceWork[i], LEN, tmp);
	}
	delete tmp;
	return is;
}

ifstream& operator>>(ifstream& in, Teacher& obj)
{
	in >> dynamic_cast<Person&>(obj);
	in.ignore(80, '|');
	in.getline(obj.occupation, 80, '|');
	//in.clear();
	in.getline(obj.specialization, 80, '|');
	//in.clear();
	for (int i = 0; i < 3; i++)
	{
		if(i!=0) in.ignore(1000000, '|');
		in.getline(obj.scienceWork[i], 80, '|');
		//if(i!=2)in.clear();
	}
	return in;
}


void Teacher::Find()
{
	Teacher Temp;
	int check;
	char* tmp;
	do
	{
		std::cout << "�������� �������� ��� ������" << endl << "1.�������" << endl << "2.���" << endl << "3.��������" << endl << "4.��� ��������" << endl;
		std::cout << "5.���������" << endl << "6.�������������" << endl << "7.������� ������" << endl << "8. �����" << endl;
		int a;
		a = InputInt(1, 8);
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
			rewind(stdin);
			std::cout << "������� ���������: ";
			tmp = InputRussian();
			strcpy_s(this->occupation, LEN, tmp);
			break;

		}
		case 6:
		{
			rewind(stdin);
			std::cout << "������� �������������: ";
			tmp = InputRussian();
			strcpy_s(this->specialization, LEN, tmp);
			break;

		}
		case 7:
		{
			rewind(stdin);
			std::cout << "������� ������� ������: ";
			for (int i = 0; i < 3; i++)
			{
				rewind(stdin);
				tmp = InputRussian();
				strcpy_s(this->scienceWork[i], LEN, tmp);
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

ostream& operator<<(ostream& out, const Teacher& obj)
{

	out << static_cast<const Person&>(obj);
	out.setf(ios::left);
	out << setw(15) << obj.occupation << setw(15) << obj.specialization;
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			out << setw(20)<< obj.scienceWork[i]  << endl;
			continue;
		}
		out << setw(95) << " " << obj.scienceWork[i] << endl;
	}
	out.unsetf(ios::left);
	return out;
}

ofstream& operator<<(ofstream& out, Teacher& obj)
{
	out << dynamic_cast<Person&>(obj);
	out.setf(ios::left);
	out << setw(15) << obj.occupation << '|' << setw(15) << obj.specialization << '|';
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			out << setw(20) << obj.scienceWork[i] << '|' << endl;
			continue;
		}
		out << setw(95) << " " << '|' << setw(20) << obj.scienceWork[i] << '|' << endl;
	}
	out.unsetf(ios::left);
	return out;
}

void Teacher::head_of_sheet()
{

	std::cout.setf(ios::left);
	std::cout << setw(5) << "�" << setw(15) << "�������" << setw(15) << "���" << setw(15) << "��������" << setw(15) << "��� ��������";
	std::cout << setw(15) << "���������" << setw(15) << "�������������" << setw(20) << "������� ������" << endl;

	std::cout.unsetf(ios::left);
}
