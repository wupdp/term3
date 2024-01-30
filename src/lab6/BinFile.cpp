#include "BinFile.h"

template<class T>
BinFile<T>::BinFile(string _name) : File(_name) {}

template<class T>
BinFile<T>::~BinFile() {
	ft.close();
}

template<typename T>
bool BinFile<T>::is_open()
{
	if (!ft.is_open())
		return false;
	else
		return true;
}

template<typename T>
bool BinFile<T>::feof()
{
	if (!ft.eof())
		return false;
	else
		return true;
}

template <typename T>
bool BinFile<T>::open_read_file()
{
	ft.open(file_name, ios::in | ios::binary);
	if (!ft.is_open())
	{
		cout << "������ �������� �����!" << endl;
		return false;
	}
	else
		return true;
}

template <typename T>
bool BinFile<T>::open_write_file()
{
	ft.open(file_name, ios::out | ios::binary);
	if (!ft.is_open())
	{
		cout << "������ �������� �����!" << endl;
		return false;
	}
	else
		return true;
}

template <typename T>
void BinFile<T>::read_file(T& temp)
{
	ft >> temp;
}

template <typename T>
void BinFile<T>::write_file(T& temp)
{
	ft << temp;
}

