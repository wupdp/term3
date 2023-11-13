#include "../headers/party_teacher.h"
#include <iostream>

PartyTeacher::PartyTeacher() {
    party_work = "";
}

PartyTeacher::PartyTeacher(const string &name, int age, const string &speciality,
                           vector<string> &publications, const string &party,
                           const vector<string> &biography, const string &work) : Teacher(name, age, speciality,
                                                                                          publications),
                                                                                  PartyMember(name, age, party,
                                                                                              biography),
                                                                                  party_work(work) {}

void PartyTeacher::display_info() const {
    PartyMember::display_info();
    cout << "Specialty: " << specialty << endl;
    cout << "Publications: " << endl;
    for (const auto &publication: publications) {
        cout << "- " << publication << endl;
    }
    cout << "Role in party: " << party_work << endl;
}

void PartyTeacher::set_work(const string &work) {
    this->party_work = work;
}

string PartyTeacher::get_work() {
    return party_work;
}

ostream &operator<<(ostream &os, const PartyTeacher &partyTeacher) {
    os << "Name: " << partyTeacher.name << endl;
    os << "Age: " << partyTeacher.age << endl;
    os << "Specialty: " << partyTeacher.specialty << endl;

    os << "Publications: ";
    for (const auto &publication: partyTeacher.publications) {
        os << endl << "\t" << publication;
    }
    os << endl;
    os << "Party Name: " << partyTeacher.party_name << endl;
    os << "Biography: ";
    for (const auto &info: partyTeacher.biography) {
        os << endl << "\t" << info;
    }
    os << endl;

    os << "Party Work: " << partyTeacher.party_work << endl;

    return os;
}

PartyTeacher::~PartyTeacher() {
    biography.clear();
    publications.clear();
}
