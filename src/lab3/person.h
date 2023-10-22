#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
private:
    std::string name;
    int birth_year;

public:
    Person(const std::string& name, int birth_year);

    std::string get_name() const;
    void set_name(const std::string& name);

    int get_birth_year() const;
    void set_birth_year(int birth_year);

    void display_info() const;
};

#endif  // PERSON_H