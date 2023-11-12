#include "party_member.h"
#include <iostream>

PartyMember::PartyMember() {
    party_name = "";
}

PartyMember::PartyMember(const string& name, int age, const string& party_name, const vector<string>& biography)
        : Person(name, age), party_name(party_name), biography(biography) {}

string PartyMember::get_party_name() const {
    return party_name;
}

void PartyMember::set_party_name(const string& party) {
    this->party_name = party;
}

vector<string> PartyMember::get_biography() const {
    return biography;
}

void PartyMember::set_biography(const std::vector<string>& text) {
    this->biography = text;
}

void PartyMember::display_info() const {
    Person::display_info();
    cout << "Party Name: " << party_name << endl;
    cout << "Biography: " << endl;
    for (const auto& entry : biography) {
        cout << "- " << entry << endl;
    }
}

ostream& operator<<(ostream& os, const PartyMember& party_member) {
    os << "Name: " << party_member.name << endl;
    os << "Age: " << party_member.age << endl;
    os << "Party Name: " << party_member.party_name << endl;
    os << "Biography: ";
    for (const auto& info : party_member.biography) {
        os << endl << "\t"<< info;
    }
    os << endl;

    return os;
}