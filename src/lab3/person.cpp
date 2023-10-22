#include "person.h"
#include <iostream>

Person::Person(const std::string& name, int birth_year)
        : name(name), birth_year(birth_year) {}

std::string Person::get_name() const {
    return name;
}

void Person::set_name(const std::string& name) {
    this->name = name;
}

int Person::get_birth_year() const {
    return birth_year;
}

void Person::set_birth_year(int birth_year) {
    this->birth_year = birth_year;
}

void Person::display_info() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Birth Year: " << birth_year << std::endl;
}