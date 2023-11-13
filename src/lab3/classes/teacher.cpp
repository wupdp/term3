#include "../headers/teacher.h"
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

ostream& operator<<(ostream& os, const Teacher& teacher) {
    os << "Name: " << teacher.name << endl;
    os << "Age: " << teacher.age << endl;
    os << "Specialty: " << teacher.specialty << endl;

    os << "Publications: ";
    for (const auto& publication : teacher.publications) {
        os << endl << "\t" <<publication;
    }
    os << endl;
    return os;
}

Teacher::~Teacher() {
    publications.clear();
}
