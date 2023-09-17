#include <iostream>

using namespace std;

class Massive {
public:
    Massive();

    explicit Massive(int);

    Massive(const Massive &other);

    Massive& operator=(const Massive& other) noexcept;

    ~Massive();

    void show();

    void show(int);

    void enter();

    void enter(int);

    void add(int);

    void crossing(Massive &, Massive &);

private:
    int count;
    int *elements;
};
