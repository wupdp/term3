#include "person.h"
#include <iostream>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
Person::Person() {
    name = "";
    age = 0;
}

Person::Person(const string& name, int age)
        : name(name), age(age) {}

string Person::get_name() const {
    return name;
}

void Person::set_name(const string& text) {
    this->name = text;
}

int Person::get_birth_year() const {
    return age;
}

void Person::set_birth_year(int year) {
    this->age = year;
}

void Person::display_info() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Birth Year: " << age << std::endl;
}

#pragma clang diagnostic pop