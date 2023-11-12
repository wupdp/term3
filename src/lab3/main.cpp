#include "party_teacher.h"
#include "iostream"
//TODO перегрузить операторы
//TODO
#define NAME "Merlin Monro"
#define AGE 29
#define SPEC "Doctor of Science"
#define PUBLs {"SW1", "SW2", "SW3"}
#define PARTY "CPSU"
#define BIO {"Borned in Shchuchin", "Studied at BSUIR"}
#define WORK "Agitator"

int main() {
    PartyTeacher woman;
    woman.set_biography(BIO);
    woman.set_birth_year(AGE);
    woman.set_specialty(SPEC);
    woman.set_publications(PUBLs);
    woman.set_name(NAME);
    woman.set_party_name(PARTY);
    woman.set_work("The member");
    std::cout << woman;
    return 0;
}
