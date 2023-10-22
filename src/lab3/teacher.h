#ifndef TEACHER_H
#define TEACHER_H

#include "person.h"
#include <string>
#include <vector>

class Teacher : public Person {
private:
    std::string specialty;
    std::vector<std::string> publications;

public:
    Teacher(const std::string& name, int birth_year, const std::string& specialty, const std::vector<std::string>& publications);

    std::string get_specialty() const;
    void set_specialty(const std::string& specialty);

    std::vector<std::string> get_publications() const;
    void set_publications(const std::vector<std::string>& publications);

    void display_info() const;
};

#endif  // TEACHER_H