#include "../headers/String.h"
#include <cstring>

String::String() : data(nullptr), size(0) {}

String::String(const char* str) {
    size = std::strlen(str);
    data = new char[size + 1];
    std::strcpy(data, str);
}

String::String(const String& other) {
    size = other.size;
    data = new char[size + 1];
    std::strcpy(data, other.data);
}

String::~String() {
    delete[] data;
}

String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = new char[size + 1];
        std::strcpy(data, other.data);
    }
    return *this;
}

String String::operator+(const String& other) const {
    String result;
    result.size = size + other.size;
    result.data = new char[result.size + 1];
    std::strcpy(result.data, data);
    std::strcat(result.data, other.data);
    return result;
}

String& String::operator+=(const String& other) {
    *this = *this + other;
    return *this;
}

String& String::operator++() {
    // Реализация префиксного инкремента
    char* newData = new char[size + 2];
    std::strcpy(newData, data);
    newData[size] = ' ';
    newData[size + 1] = '\0';
    delete[] data;
    data = newData;
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
        char* newData = new char[size];
        std::strncpy(newData, data, size - 1);
        newData[size - 1] = '\0';
        delete[] data;
        data = newData;
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
        return String();

    int sub_length = end_index - start_index + 1;
    char* sub_data = new char[sub_length + 1];
    std::strncpy(sub_data, data + start_index, sub_length);
    sub_data[sub_length] = '\0';

    return String(sub_data);
}