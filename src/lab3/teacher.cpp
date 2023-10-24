#include "teacher.h"
#include <iostream>

Teacher::Teacher() {
    name = "";
    age = 0;
    specialty = "";
}

Teacher::Teacher(const string& name, int age, const string& specialty, const vector<string>& publications)
        : Person(name, age), specialty(specialty), publications(publications) {}

string Teacher::get_specialty() const {
    return specialty;
}

void Teacher::set_specialty(const string& text) {
    this->specialty = text;
}

vector<string> Teacher::get_publications() const {
    return publications;
}

void Teacher::set_publications(const vector<string>& text) {
    this->publications = text;
}

void Teacher::display_info() const {
    Person::display_info();
    cout << "Specialty: " << specialty << endl;
    cout << "Publications: " << endl;
    for (const auto& publication : publications) {
        cout << "- " << publication << endl;
    }
}
