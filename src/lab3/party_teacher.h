//
// Created by wupdp on 23.10.23.
//

#ifndef LAB3_PARTY_TEACHER_H
#define LAB3_PARTY_TEACHER_H

#include "party_member.h"
#include "teacher.h"


class PartyTeacher : virtual public Teacher, virtual public PartyMember {
private:
    string party_work;
public:
    PartyTeacher();
    PartyTeacher(const string &name, int birth_year, const string &specialty, vector<string>&publications,
                 const string &party_name, const vector<string> &biography, const string &party_work);

    void display_info() const override;


};


#endif //LAB3_PARTY_TEACHER_H
