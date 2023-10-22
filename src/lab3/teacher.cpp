#include "teacher.h"
#include <iostream>

Teacher::Teacher(const std::string& name, int birth_year, const std::string& specialty, const std::vector<std::string>& publications)
        : Person(name, birth_year), specialty(specialty), publications(publications) {}

std::string Teacher::get_specialty() const {
    return specialty;
}

void Teacher::set_specialty(const std::string& specialty) {
    this->specialty = specialty;
}

std::vector<std::string> Teacher::get_publications() const {
    return publications;
}

void Teacher::set_publications(const std::vector<std::string>& publications) {
    this->publications = publications;
}

void Teacher::display_info() const {
    Person::display_info();
    std::cout << "Specialty: " << specialty << std::endl;
    std::cout << "Publications: " << std::endl;
    for (const auto& publication : publications) {
        std::cout << "- " << publication << std::endl;
    }
}