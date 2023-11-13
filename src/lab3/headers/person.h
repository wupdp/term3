#pragma once

#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person();
    Person(const string& name, int age);
    ~Person();
    string get_name() const;
    void set_name(const string& name);

    int get_age() const;
    void set_age(int age);

    virtual void display_info() const;
    friend ostream& operator<<(ostream& os, const Person& person);
};