#include "../headers/String.h"
#include <cstring>

String::String() : data(nullptr), size(0) {}

String::String(const char* str) {
    size = strlen(str);
    data = new char[size + 1];
    strcpy(data, str);
}

String::String(const String& other) {
    size = other.size;
    data = new char[size + 1];
    strcpy(data, other.data);
}

String::~String() {
    delete[] data;
}

String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = new char[size + 1];
        strcpy(data, other.data);
    }
    return *this;
}

String String::operator+(const String& other) const {
    String result;
    result.size = size + other.size;
    result.data = new char[result.size + 1];
    strcpy(result.data, data);
    strcat(result.data, other.data);
    return result;
}

String& String::operator+=(const String& other) {
    *this = *this + other;
    return *this;
}

String& String::operator++() {
    // Реализация префиксного инкремента
    char* new_data = new char[size + 2];
    strcpy(new_data, data);
    new_data[size] = ' ';
    new_data[size + 1] = '\0';
    delete[] data;
    data = new_data;
    size++;
    return *this;
}

String String::operator++(int) {
    // Реализация постфиксного инкремента
    String copy(*this);
    ++(*this);
    return copy;
}

String& String::operator--() {
    // Реализация префиксного декремента
    if (size > 0) {
        char* new_data = new char[size];
        strncpy(new_data, data, size - 1);
        new_data[size - 1] = '\0';
        delete[] data;
        data = new_data;
        size--;
    }
    return *this;
}

String String::operator--(int) {
    // Реализация постфиксного декремента
    String copy(*this);
    --(*this);
    return copy;
}

bool String::operator>(const String& other) const {
    if(size > other.size)
        return 1;
    else
        return 0;
}

bool String::operator<(const String& other) const {
    if(size < other.size)
        return 1;
    else
        return 0;
}

std::ostream& operator<<(std::ostream& os, const String& str) {
    os << str.data;
    return os;
}

std::istream& operator>>(std::istream& is, String& str) {
    char buffer[1024]; // Буфер для чтения
    is.getline(buffer, sizeof(buffer));
    str = (String)buffer; // Присваиваем считанную строку объекту String
    return is;
}

String String::substring(int start_index, int end_index) {
    if (start_index < 0 || start_index >= static_cast<int>(size) || end_index <= start_index || end_index >= static_cast<int>(size))
        return String();    //Проверка на верный размер

    int sub_length = end_index - start_index + 1;
    char* sub_data = new char[sub_length + 1];
    std::strncpy(sub_data, data + start_index, sub_length);
    sub_data[sub_length] = '\0';

    return String(sub_data);
}

const String String::operator+(const char * str) const {
    return (*this) + (const String)str;
}

const String &String::operator+=(const char *str) {
    *this = *this + (String)str;
    return *this;
}

String operator+(const char *str1, const String &str2) {
    return str2 + (String)str1;
}
