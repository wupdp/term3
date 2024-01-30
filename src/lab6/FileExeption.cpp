#include "FileExeption.h"

bool check_file(string name_file)
{
    ifstream filee(name_file, ios::in);
    try
    {
        if (!filee)
            throw (FileExeption(1, "������ �������� �����", "������� ����� �� ����������"));
        if (!filee.is_open())
            throw (FileExeption(3, "������ �������� �����", "������ ���� �� ��������"));

    }
    catch (FileExeption obj)
    {
        cin.clear();
        obj.show_err();
        return 0;
    }
    return true;
}

void FileExeption::show_err()
{
    cout << "��� ������:" << Code << endl;
    cout << Type << endl;
    cout << msg << endl;
}
