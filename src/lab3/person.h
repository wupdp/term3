#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person();
    Person(const string& name, int age);

    string get_name() const;
    void set_name(const string& name);

    int get_birth_year() const;
    void set_birth_year(int birth_year);

    virtual void display_info() const;
};

#endif  // PERSON_H