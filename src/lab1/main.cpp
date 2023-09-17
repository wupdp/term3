#include <iostream>
#include "massive.h"
using namespace std;
int main() {
    massive_class mas1(3);
    mas1.enter();
    mas1.show(3);
    massive_class mas2(5);
    mas2.enter();
    mas2.show();
    massive_class mas3(3);
    mas3.crossing(mas1, mas2);
    mas3.show();
    return 0;
}
