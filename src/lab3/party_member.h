#ifndef PARTY_MEMBER_H
#define PARTY_MEMBER_H

#include "person.h"
#include <string>
#include <vector>

class PartyMember : virtual public Person {
private:
    std::string party_name;
    std::vector<std::string> biography;

public:
    PartyMember(const std::string& name, int birth_year, const std::string& party_name, const std::vector<std::string>& biography);

    std::string get_party_name() const;
    void set_party_name(const std::string& party_name);

    std::vector<std::string> get_biography() const;
    void set_biography(const std::vector<std::string>& biography);

    void display_info() const;
};

#endif  // PARTY_MEMBER_H