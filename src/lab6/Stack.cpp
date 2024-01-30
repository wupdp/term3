#pragma once
#include "Stack.h"




template <typename T>
void Stack<T>::HeadTable()
{
	T obj;

	obj.head_of_sheet();
}

template <class T>
T Stack<T>::delete_from_head()
{
	T data;
	if (QueueEmpty())
	{
		cout << "������� �����" << endl;
		return data;
	}
	data = Head->Data;
	if (Head == Tail)
	{
		Head = Tail = nullptr;
	}
	else
	{
		Head = Head->Next;
		Head->Prev = nullptr;
	}
	this->Size--;
	return data;
}

template <class T>
T Stack<T>::delete_from_tail()
{
	T data;
	if (QueueEmpty())
	{
		cout << "������� �����" << endl;
		return data;
	}
	data = Tail->Data;
	Node<T>* n = Tail;
	if (Tail == Head)
	{
		delete Head;
		Head = Tail = nullptr;
	}
	else
	{
		Tail = Tail->Prev;
		Tail->Next = nullptr;
	}
	this->Size--;
	return data;
}


template <class T>
void Stack<T>::push_t(T obj)
{
	if (Head != nullptr)
	{
		Node<T>* n = new Node<T>;
		n->Data = obj;
		n->Next = nullptr;
		n->Prev = Tail;
		Tail->Next = n;
		Tail = n;
	}
	else
	{
		Head = new Node<T>;
		Head->Data = obj;
		Head->Next = nullptr;
		Head->Prev = nullptr;
		Tail = Head;
	}
	this->Size++;
}

template<class T>
void Stack<T>::push_h(T obj)
{
	if (Head != nullptr)
	{
		Node<T>* n = new Node<T>;
		n->Data = obj;
		n->Next = Head;
		n->Prev = nullptr;
		Head->Prev = n;
		Head = n;
	}
	else
	{
		Head = new Node<T>;
		Head->Data = obj;
		Head->Next = nullptr;
		Head->Prev = nullptr;
		Tail = Head;
	}
	this->Size++;
}

template <class T>
void Stack<T>::output()
{
	if (QueueEmpty())
	{
		cout << "������� �����" << endl;
		return;
	}
	Node<T>* tmpq = Head;
	int i = 1;

	for (tmpq; tmpq != nullptr; tmpq = tmpq->Next)
	{
		cout.setf(ios::left);
		cout << setw(5) << i++ << tmpq->Data << endl;
	}
	cout.setf(ios::left);
}


template <class T>
T Stack<T>::delete_(int num)
{
	T data;
	if (QueueEmpty())
	{
		cout << "������� �����" << endl;
		return data;
	}
	if (num - 1 == 0)
	{
		delete_from_head();
		
	}
	if (num == Size)
	{
		delete_from_tail();
		
	}
	Node<T>* cur = Head;
	for (int i = 0; i < num - 1; i++)
		cur = cur->Next;
	Node<T>* prev = cur->Prev;
	Node<T>* next = cur->Next;
	data = cur->Data;
	this->Size--;
	prev->Next = next;
	next->Prev = prev;
	delete cur;
	return data;
}


template <class T>
bool Stack<T>::QueueEmpty()
{
	if (Size)
		return false;
	return true;
}

template<class T>
T& Stack<T>::operator[](int num)
{
	Node<T>* cur = Head;
	if (num < 0 || num > Size) return cur->Data;
	for (int i = 0; i < num; i++) { cur = cur->Next; }
	return cur->Data;
}

template <class T>
void Stack<T>::delete_stack()
{
	while (this->Head)
	{
		this->delete_from_head();
	}
}

template <typename T>
Stack<T> Stack<T>::search(T obj)
{
	Stack<T> rez;
	Node<T>* tmp = Tail;
	while (tmp) {
		if (tmp->Data == obj)
			rez.push_t(tmp->Data);
		tmp = tmp->Prev;
	}
	return rez;
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack<T>& other)
{
	this->delete_stack();
	Node<T>* tmp = other.Head;
	while (tmp) {
		this->push_t(tmp->Data);
		tmp = tmp->Prev;
	}
	return *this;
}





























//template <typename T>
//void Stack<T>::textfile_out(string fname)
//{
//	TextFile<T> fl_txt(fname);
//	fl_txt.openWriteFile();
//	Node<T>* tmp = Head;
//	while (tmp)
//	{
//		fl_txt.writeFile(tmp->Data);
//		tmp = tmp->Next;
//	}
//}
//
//template <typename T>
//void Stack<T>::textfile_in(string fname)
//{
//	TextFile<T> fl_txt(fname);
//	fl_txt.openReadFile();
//	T temp;
//	while (1)
//	{
//		fl_txt.readFile(temp);
//		if (fl_txt.feof()) break;
//		push_t(temp);
//	}
//}
//
//template <typename T>
//void Stack<T>::binfile_out(string fname)
//{
//	BinFile<T> fl_bin(fname);
//	fl_bin.openWriteFile();
//	Node<T>* tmp = Head;
//	while (tmp)
//	{
//		fl_bin.writeFile(tmp->Data);
//		tmp = tmp->Next;
//	}
//}
//
//template <typename T>
//void Stack<T>::binfile_in(string fname)
//{
//	BinFile<T> fl_bin(fname);
//	fl_bin.openReadFile();
//	T temp;
//	while (1)
//	{
//		fl_bin.readFile(temp);
//		if (fl_bin.feof()) break;
//		push_t(temp);
//	}
//}








