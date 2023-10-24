//
// Created by wupdp on 23.10.23.
//
#include "party_teacher.h"
#include <iostream>

PartyTeacher::PartyTeacher() {
    party_work = "";
}

PartyTeacher::PartyTeacher(const string &name, int age, const string &speciality,
                           vector<string>&publications, const string &party,
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
