#include "InputExeption.h"

int InputInt(int min, int max)
{
	int Temp = 0;
	while (true)
	{
		try
		{
			cin >> Temp;
			if (cin.fail() || cin.peek() != '\n')
				throw InputExeption(111, "������ ������� ������", "������� ����� �����");
			if (Temp > max || Temp < min) throw InputExeption(112, "������ ������ �� �������", "������� ����� � ��������� ���������");
			return Temp;
		}
		catch (InputExeption obj)
		{
			cin.clear();
			cin.ignore(Len, '\n');
			obj.show_err();
			cout << "������� ����� ����� � �������� �� " << min << " �� " << max << endl;
		}
	}

}
double InputDouble(int min, int max)
{
	int Temp = 0;
	while (true)
	{
		try
		{
			cin >> Temp;
			if (cin.fail() || cin.peek() != '\n') throw InputExeption(111, "������ ������� ������", "������� ������������ �����");
			if (Temp > max || Temp < min) throw InputExeption(112, "������ ������ �� �������", "������� ����� � ��������� ���������");
			return Temp;
		}

		catch (InputExeption obj)
		{
			cin.clear();
			cin.ignore(Len, '\n');
			obj.show_err();
			cout << "������� ����� ����� � �������� �� " << min << " �� " << max << endl;
		}
	}
}
char* InputRussian()
{

	while (true)
	{
		try
		{
			char* Temp = new char[Len];
			rewind(stdin);
			cin.getline(Temp, Len);
			if (cin.fail())throw InputExeption(121, "������ ������ �� �������", "������� ������ ������ 80 �������� ");
			for (int i = 0; i < strlen(Temp); i++)
			{
				if ((Temp[i] < '�' or Temp[i] > '�') and (Temp[i] < '�' or Temp[i] > '�') and Temp[i] != ' ' and Temp[i] != ',' and Temp[i] != '.' and Temp[i] != '-')
					throw InputExeption(122, "������ ����� ���������� ������", "������� ������ ����������");
			}
			return Temp;
		}
		catch (bad_alloc ex)
		{
			cout << "������ ��������� ������ ��� ������ �� " << Len << "��������" << std::endl;
			exit(1);
		}
		catch (InputExeption obj)
		{
			cin.clear();
			obj.show_err();
		}
	}
}
char* InputEnglish()
{
	while (true)
	{
		try
		{
			char* Temp = new char[Len];
			rewind(stdin);
			cin.clear();
			cin.getline(Temp, Len);
			if (cin.fail())throw InputExeption(121, "������ ������ �� �������", "������� ������ ������ 80 �������� ");
			for (int i = 0; i < strlen(Temp); i++)
			{
				if ((Temp[i] < 'A' or Temp[i] > 'Z') and (Temp[i] < 'a' or Temp[i] > 'z') and Temp[i] != ' ' and Temp[i] != ',' and Temp[i] != '.' and Temp[i] != '-')
					throw InputExeption(122, "������ ����� ���������� ������", "������� ������ ���������");
			}
			return Temp;
		}
		catch (bad_alloc ex)
		{
			cout << "������ ��������� ������ ��� ������ �� " << Len << "��������" << endl;
			exit(1);
		}
		catch (InputExeption obj)
		{
			cin.clear();
			obj.show_err();
		}
	}
}

void InputExeption::show_err()
{
	cout << "��� ������:" << Code << endl;
	cout << Type << endl;
	cout << msg << endl;
}