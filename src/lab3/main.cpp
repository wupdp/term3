#include "headers/header.h"


int main() {
    PartyTeacher woman;
    Teacher man;
    man.set_name("Albert Einstein");
    man.set_age(145);
    man.set_specialty("Theoretical physicist");
    man.set_publications({"Folgerungen aus den Kapillaritätserscheinungen","Thermodynamische","Kinetische Theorie"});

    cout << man << endl;

    woman.set_biography(BIO);
    woman.set_age(AGE);
    woman.set_specialty(SPEC);
    woman.set_publications(PUBLs);
    woman.set_name(NAME);
    woman.set_party_name(PARTY);
    woman.set_work(WORK);

    cout << woman;

    return 0;
}
