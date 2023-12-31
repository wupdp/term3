#ifndef LAB4_MENU_H
#define LAB4_MENU_H
#include "stack.h"

class Menu {
private:
    int choice;
public:
    ~Menu();
    Menu();
    template <typename T>
    void start(Stack<T> &stack);
private:
    void top();
    static void clear();
};

#include "../classes/Menu.inl"
#endif //LAB4_MENU_H
