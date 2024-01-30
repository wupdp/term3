#pragma once
#include "Person.h"
#include "Partymember.h"
#include "Teacher.h"
#include "PartyTeacher.h"

//#include "Queue.h"
#include "Stack.cpp"
using namespace std;

template <typename T>
class Interface
{
public:
	Interface() {};

	~Interface() {};

	void menu();
	void menu(Stack<T>& obj, string tfile, string bfile);
};




