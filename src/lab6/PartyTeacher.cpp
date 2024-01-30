#include "PartyTeacher.h"


double PartyTeacher::get_contributions() { return contributions; }
void PartyTeacher::set_contributions(int temp) { this->contributions = temp; }

PartyTeacher PartyTeacher:: operator=(PartyTeacher& obj)
{
	*((Teacher*)this) = (Teacher&)obj;
	*((PartyMember*)this) = (PartyMember&)obj;
	this->contributions = obj.contributions;
	return *this;
}

bool PartyTeacher:: operator==(const PartyTeacher& obj)
{
	if (!(*((Teacher*)this) == (Teacher&)obj)) return false;
	if (!(*((PartyMember*)this) == (PartyMember&)obj)) return false;
	


	if (obj.contributions != 0)
	{
		if (contributions != obj.contributions) return false;
	}


	return true;
}

istream& operator>>(istream& is, PartyTeacher& obj)
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
	std::cout << "������� �������� �����������: ";
	rewind(stdin);
	tmp = InputRussian();
	strcpy_s(obj.org_name, LEN, tmp);
	std::cout << "������� ��� ����������: ";
	rewind(stdin);
	obj.enter_year = InputInt(1900, 2022);
	std::cout << "������� �������������: ";
	for (int i = 0; i < 3; i++)
	{
		rewind(stdin);
		tmp = InputRussian();
		strcpy_s(obj.biography[i], LEN, tmp);
	}
	delete tmp;
	cout << "������� ����������� �����: ";
	rewind(stdin);
	obj.contributions = InputDouble(-1, 10000);
	return is;
}

ifstream& operator>>(ifstream& in, PartyTeacher& obj)
{
	in >> dynamic_cast<Person&>(obj);
	in.ignore(80, '|');
	in.getline(obj.occupation, 80, '|');
	//in.clear();
	in.getline(obj.specialization, 80, '|');
	//in.clear();
	in.getline(obj.org_name, 80, '|');
	//in.clear();
	in >> obj.enter_year;
	in >> obj.contributions;
	in.ignore(80, '|');
	for (int i = 0; i < 3; i++)
	{
		if (i != 0) in.ignore(1000000, '|');
		in.getline(obj.scienceWork[i], 80, '|');
		//if (i != 2)in.clear();
		//if (i != 0) in.ignore(1000000, '|');
		in.getline(obj.biography[i], 80, '|');
		//if (i != 2)in.clear();
	}
	in.unsetf(ios::left);
	return in;
}

fstream& operator<<(fstream& in, PartyTeacher& ob)
{
	in << dynamic_cast<Person&>(ob);
	in.write(reinterpret_cast<char*> (&ob.occupation), sizeof(ob.occupation));
	in.write(reinterpret_cast<char*> (&ob.specialization), sizeof(ob.specialization));
	in.write(reinterpret_cast<char*> (&ob.org_name), sizeof(ob.org_name));
	in.write(reinterpret_cast<char*> (&ob.enter_year), sizeof(ob.enter_year));
	in.write(reinterpret_cast<char*> (&ob.contributions), sizeof(ob.contributions));
	for (int i = 0; i < 3; i++)
	{
		in.write(reinterpret_cast<char*> (&ob.scienceWork[i]), sizeof(ob.scienceWork[i]));
		in.write(reinterpret_cast<char*> (&ob.biography[i]), sizeof(ob.biography[i]));
	}
	return in;
}

fstream& operator>>(fstream& out, PartyTeacher& ob)
{
	out >> dynamic_cast<Person&>(ob);
	out.read(reinterpret_cast<char*> (&ob.occupation), sizeof(ob.occupation));
	out.read(reinterpret_cast<char*> (&ob.specialization), sizeof(ob.specialization));
	out.read(reinterpret_cast<char*> (&ob.org_name), sizeof(ob.org_name));
	out.read(reinterpret_cast<char*> (&ob.enter_year), sizeof(ob.enter_year));
	out.read(reinterpret_cast<char*> (&ob.contributions), sizeof(ob.contributions));
	for (int i = 0; i < 3; i++)
	{
		out.read(reinterpret_cast<char*> (&ob.scienceWork[i]), sizeof(ob.scienceWork[i]));
		out.read(reinterpret_cast<char*> (&ob.biography[i]), sizeof(ob.biography[i]));
	}
	return out;
}

ostream& operator<<(ostream& out, const PartyTeacher& obj)
{
	out << static_cast<const Person&>(obj);
	out.setf(ios::left);
	out << setw(15) << obj.occupation << setw(15) << obj.specialization;
	out << setw(15) << obj.org_name << setw(15) << obj.enter_year << setw(15) << obj.contributions;
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			out << setw(20) << obj.scienceWork[i] << setw(20) << obj.biography[i] << endl;
		}
		else out << setw(140) << " " << setw(20) << obj.scienceWork[i] << setw(20) << obj.biography[i] << endl;
	}
	out.unsetf(ios::left);
	return out;
}

ofstream& operator<<(ofstream& out, PartyTeacher& obj)
{
	out << dynamic_cast<Person&>(obj);
	out.setf(ios::left);
	out << setw(15) << obj.occupation << '|' << setw(15) << obj.specialization << '|';
	out << setw(15) << obj.org_name << '|' << setw(15) << obj.enter_year << setw(15) << obj.contributions << '|';
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			out << setw(20) << obj.scienceWork[i] << '|' << setw(20) << obj.biography[i] << '|' << endl;
		}
		else out << setw(142) << " " << '|' << setw(20) << obj.scienceWork[i] << '|' << setw(20) << obj.biography[i] << '|' << endl;
	}
	out.unsetf(ios::left);
	return out;
}

void PartyTeacher::head_of_sheet()
{
	cout.setf(ios::left);
	cout << setw(5) << "�" << setw(15) << "�������" << setw(15) << "���" << setw(15) << "��������" << setw(15) << "��� ��������";
	cout << setw(15) << "���������" << setw(15) << "�������������";
	cout << setw(15) << "����.�����." << setw(15) << "��� ����������" << setw(15) << "������.�����" << setw(15) << "������� ������" << setw(20) << "�������������" << endl;
	cout.unsetf(ios::left);
}

void PartyTeacher::Find()
{
	int check;
	char* tmp;
	do
	{
		rewind(stdin);
		cout << "�������� �������� ��� ������" << endl << "1.�������" << endl << "2.���" << endl << "3.��������" << endl << "4.��� ��������" << endl;
		cout << "5.���������" << endl << "6.�������������" << endl << "7.������� ������" << endl;
		cout << "8.�������� ����������� " << endl << "9.��� ����������" << endl << "10.�������������" << endl;
		cout << "11.����������� ����� " << endl << "12. �����" << endl;
		int a;
		a = InputInt(1, 12);
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
			rewind(stdin);
			std::cout << "������� �������� �����������: ";
			tmp = InputRussian();
			strcpy_s(this->org_name, LEN, tmp);
			cout << endl;
			break;
		}
		case 9:
		{
			std::cout << "������� ��� ����������: ";
			this->enter_year = InputInt(MIN_YEAR, MAX_YEAR);
			cout << endl;
			break;
		}
		case 10:
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
		case 11:
		{
			cout << "������� ����������� �����:  ";
			this->contributions = InputDouble(-1, 10000);
			cout << endl;
			break;
		}
		case 12:
		{
			return;
		}
		}
		std::cout << "�������� ��������� ��� ������? 1 - ��, 0 - ���";

		check = InputInt(0, 1);
		std::cout << endl;
	} while (check == 1);
}