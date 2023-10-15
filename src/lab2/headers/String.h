#include <iostream>

class String {
private:
    char* data;
    size_t size;

public:
    String();
    explicit String(const char* str);
    String(const String& other);
    ~String();

    String& operator=(const String& other);
    String operator+(const String& other) const;
    String& operator+=(const String& other);
    String& operator++();
    String operator++(int);
    String& operator--();
    String operator--(int);
    bool operator>(const String& other) const;
    bool operator<(const String& other) const;

    friend std::ostream& operator<<(std::ostream& os, const String& str);
    friend std::istream& operator>>(std::istream& is, String& str);

    String substring(int, int);

};
