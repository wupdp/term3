#pragma once

#include "party_member.h"
#include "teacher.h"

class PartyTeacher : virtual public Teacher, virtual public PartyMember {
private:
    string party_work;
public:
    PartyTeacher();
    PartyTeacher(const string &name, int birth_year, const string &specialty, vector<string>&publications,
                 const string &party_name, const vector<string> &biography, const string &party_work);
    explicit PartyTeacher(const Teacher& teacher);
    explicit PartyTeacher(const PartyMember& member);
    ~PartyTeacher();
    void display_info() const override;
    void set_work(const string& party_work);
    string get_work();
    friend ostream& operator<<(ostream& os, PartyTeacher& party_teacher);
};