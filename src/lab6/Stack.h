#pragma once
#include <iostream>
#include <ostream>
#include <iomanip> 
#include "TextFile.h"
#include "BinFile.h"
#include "FileExeption.h"

template <class T>
struct Node
{
public:
	T Data;
	Node<T>* Prev;
	Node<T>* Next;
};

using namespace std;
template <typename T>
class Stack {

private:
	Node<T>* Head;
	Node<T>* Tail;
	int Size;


public:
	Stack()
	{
		Head = nullptr;
		Tail = nullptr;
		Size = 0;
	}

	Stack(const Stack<T>& obj)
	{
		Head = nullptr;
		Tail = nullptr;
		this->Size = 0;
		Node<T>* Temp = obj.Head;
		while (Temp)
		{
			this->push_t(Temp->Data);
			Temp = Temp->Next;
		}
	}

	~Stack()
	{
		delete_stack();
	}

	int size() { return this->Size; }

	void push_t(T value);                                    //�������� � ����� �������
	void push_h(T value);                                    //�������� � ����� �������

	void output();                                         //����� �������      

	T delete_from_head();                                 //������� �� ������

	T delete_from_tail();                                 //������� �� ������

	T delete_(int num);

	T& operator[](int num);

	void delete_stack();

	/*void textfile_in(string fname);
	void textfile_out(string fname);
	void binfile_in(string fname);
	void binfile_out(string fname);*/
	
	bool QueueEmpty();                                     //�������� �� ������������� ��������	

	Stack<T> search(T obj);                                 //����� �� ����������

	Stack<T>& operator=(Stack<T>& other);             //���������� �����

	void HeadTable();                                      //��������� �������

};
