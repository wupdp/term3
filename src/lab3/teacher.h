#pragma once

#include "person.h"
#include <string>
#include <vector>

class Teacher : virtual public Person {
protected:
    string specialty;
    vector<string> publications;

public:
    Teacher();
    Teacher(const string& name, int age, const string& specialty, const vector<string>& publications);

    string get_specialty() const;
    void set_specialty(const string& specialty);

    vector<string> get_publications() const;
    void set_publications(const vector<string>& publications);

    void display_info() const override;
    friend ostream& operator<<(ostream& os, const Teacher& teacher);
};