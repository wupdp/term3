#include <iostream>

using namespace std;

class massive_class {
public:
    massive_class();

    explicit massive_class(int);

    massive_class(const massive_class &other);

    ~massive_class();

    void show();

    void show(int);

    void enter();

    void enter(int);

    void add(int);

    void crossing(massive_class &, massive_class &);

private:
    int count;
    int *elements;
};
