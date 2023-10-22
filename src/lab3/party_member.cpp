#include "party_member.h"
#include <iostream>

PartyMember::PartyMember(const std::string& name, int birth_year, const std::string& party_name, const std::vector<std::string>& biography)
        : Person(name, birth_year), party_name(party_name), biography(biography) {}

std::string PartyMember::get_party_name() const {
    return party_name;
}

void PartyMember::set_party_name(const std::string& party_name) {
    this->party_name = party_name;
}

std::vector<std::string> PartyMember::get_biography() const {
    return biography;
}

void PartyMember::set_biography(const std::vector<std::string>& biography) {
    this->biography = biography;
}

void PartyMember::display_info() const {
    Person::display_info();
    std::cout << "Name: " << name << std::endl;
    std::cout << "Birth Year: " << birth_year << std::endl;
}

void PartyMember::display_info() const {
    Person::display_info();
    std::cout << "Party Name: " << party_name << std::endl;
    std::cout << "Biography: " << std::endl;
    for (const auto& entry : biography) {
        std::cout << "- " << entry << std::endl;
    }
}