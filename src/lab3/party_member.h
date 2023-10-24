#ifndef PARTY_MEMBER_H
#define PARTY_MEMBER_H

#include "person.h"
#include <string>
#include <vector>

class PartyMember : virtual public Person {
protected:
    string party_name;
    vector<string> biography;

public:
    PartyMember();
    PartyMember(const string& name, int age, const string& party_name, const vector<string>& biography);

    string get_party_name() const;
    void set_party_name(const string& party_name);

    vector<string> get_biography() const;
    void set_biography(const vector<string>& biography);

    void display_info() const override;
};

#endif  // PARTY_MEMBER_H