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

ostream &operator<<(ostream &os,  PartyTeacher &partyTeacher) {
    os << dynamic_cast<Teacher&>(partyTeacher);
    os << "Party Name: " << partyTeacher.party_name << endl;
    os << "Biography: ";
    for (const string &info: partyTeacher.biography) {
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

PartyTeacher::PartyTeacher(const Teacher& teacher) {
    this->name = teacher.get_name();
    this->specialty = teacher.get_specialty();
    this->publications = teacher.get_publications();
    this->age = teacher.get_age();
}

PartyTeacher::PartyTeacher(const PartyMember& member) {
    this->party_name = member.get_party_name();
    this->biography = member.get_biography();
    this->name = member.get_name();
    this->age = member.get_age();
}
