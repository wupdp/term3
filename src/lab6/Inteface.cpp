
#include "Inteface.h"


template <typename T>
void Interface<T>::menu()
{

	int Type;

	string tfilename;
	string bfilename;
	bool fl = true;
	while (fl) {
		//SetColor(4, 0);
		cout << "�������: " << endl << "1. ���������" << endl
			<< "2. ���� �����������" << endl << "3. ���������-���� �����������" << endl << "4. �����" << endl;
		//SetColor(7, 0);
		Type = InputInt(1, 5);
		cout << endl;
		switch (Type)
		{
		case 1:
		{
			Interface<Teacher> obj;
			Stack<Teacher> q;
			tfilename = "tTeacher";
			bfilename = "bTeacher";
			obj.menu(q, tfilename, bfilename);
			break;
		}
		case 2:
		{
			Interface<PartyMember> obj;
			Stack<PartyMember> q;
			tfilename = "tPartymember.txt";
			bfilename = "bPartymember.bin";
			obj.menu(q, tfilename, bfilename);
			break;
		}
		case 3:
		{
			Interface<PartyTeacher> obj;
			Stack<PartyTeacher> q;
			tfilename = "tProfMember.txt";
			bfilename = "bProfMember.bin";
			obj.menu(q, tfilename, bfilename);
			break;
		}
		case 4:
		{
			fl = false;
		}
		}
	}

};

template <typename T>
void Interface<T>::menu(Stack<T>& obj,string tname,string bname)
{
	int v;
	bool flag = true;
	do {
		//SetColor(6, 0);
		cout << endl << "������� ��������: " << endl << "1. ���������� ��������" << endl << "2. �������� " << endl
			<< "3. �������� �������" << endl << "4. ����� �� ����������" << endl;
		cout << "5.��������� �� ��������� ����� " << endl << "6. ��������� �� ��������� �����" << endl;
		cout << "7.�������� � ��������� ���� " << endl << "8. �������� � �������� ����" << endl;
		cout << "9.����� " << endl;
		//SetColor(7, 0);
		v = InputInt(1, 9);
		cout << endl;
		switch (v)
		{
		case 1:
		{
			cout << "���� ����������:" << endl;
			T a;
			cin >> a;
			obj.push_t(a);
			break;
		}
		case 2:
		{
			//SetColor(6, 0);
			cout << endl << "������� ��������: " << endl << "1. �������� �� ������" << endl << "2. �������� �� ������" << endl
				<< "3. �������� �� �������" << endl << "4. ����� �� ������" << endl;
			//SetColor(7, 0);
			int pick;
			pick = InputInt(1, 4);
			//T temp;
			switch (pick)
			{
			case 1:
			{
				
				obj.delete_from_head();
				break;
			}
			case 2:
			{

				obj.delete_from_tail();
				break;
			}
			case 3:
			{
				cout << "������� ����� �������� ��� ��������: ";
				int num = InputInt(0, obj.size());
				obj.delete_(num);
				break;
			}
			case 4:
			{
				break;
			}
			}
			break;
		}
		case 3:
		{

			cout << "�������: " << endl;
			//SetColor(5, 0);
			obj.HeadTable();
			//SetColor(2, 0);
			obj.output();
			cout << endl;
			break;
		}
		case 4:
		{
			T f;
			f.Find();
			Stack<T> Temp = obj.search(f);

			cout << "���������:" << endl;
			if (Temp.QueueEmpty())
			{
				cout << "�� �������";
			}
			else
			{
				Temp.HeadTable();
				Temp.output();
			}

			break;
		}
		case 5:
		{
			if (check_file(tname))
			{
				
				TextFile<T> fl_txt(tname);
				fl_txt.open_read_file();
				T temp;
				while (1)
				{
					fl_txt.read_file(temp);
					if (fl_txt.feof()) break;
					obj.push_t(temp);
				}
			}
			break;
		}case 6:
		{
			if (check_file(bname))
			{
				
				BinFile<T> fl_bin(bname);
				fl_bin.open_read_file();
				T temp;
				while (1)
				{
					fl_bin.read_file(temp);
					if (fl_bin.feof()) break;
					obj.push_t(temp);
				}
			}
			break;
		}case 7:
		{
			
			TextFile<T> fl_txt(tname);
			fl_txt.openWriteFile();
			int i = 0;
			while (i<obj.size())
			{
				fl_txt.write_file(obj[i]);
				i++;
			}
			
			break;
		}case 8:
		{
			
			BinFile<T> fl_bin(bname);
			fl_bin.open_write_file();
			int i=0;
			
			while (i<obj.size())
			{
				
				fl_bin.write_file(obj[i++]);
			}
			
			break;
		}case 9:
		{
			flag = false;
		}
		}
	} while (flag);
}
