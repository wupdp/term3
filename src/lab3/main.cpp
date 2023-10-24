#include <iostream>
#include "party_teacher.h"

#define NAME "Merlin Monro"
#define AGE 29
#define SPEC "Doctor of Science"
#define PUBLs "SW1""SW2""SW3"
#define PARTY "CPSU"
#define BIO "Borned in Shchuchin" "Studied at BSUIR"
#define WORK "Agitator"

int main() {
    PartyTeacher woman;
    vector<string> text;

    woman.set_biography();
    woman.set_birth_year();
    woman.set_name();
    woman.set_party_name();
    woman.set_publications();
    woman.set_specialty();
    return 0;
}
