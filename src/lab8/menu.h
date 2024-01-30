#ifndef MENU_H
#define MENU_H
#include <iostream>
#include "stack.h"
#include <stack>

template <typename T>
class Menu {
public:
    void run();

private:
    void printMainMenu();
    int getUserChoice(int min, int max);

    void handleCustomStack();
    void printCustomStackMenu();
    void handleSTLStack();
    void printSTLStackMenu();

    void handlePush(Stack<T>& stack);
    void handlePop(Stack<T>& stack);
    void handleTop(Stack<T>& stack);
    void handleIsEmpty(const Stack<T>& stack);
    void handlePrint(const Stack<T>& stack);
    void handleCustomStackSort(Stack<T>& stack);
    void handleCustomStackErase(Stack<T>& stack);
    void handleCustomStackInsert(Stack<T>& stack);
    void handleCustomStackContains(const Stack<T>& stack);

    void handleSTLPush(std::stack<T>& stack);
    void handleSTLPop(std::stack<T>& stack);
    void handleSTLTop(const std::stack<T>& stack);
    void handleSTLIsEmpty(const std::stack<T>& stack);
    void handleSTLPrint(const std::stack<T>& stack);
};

#include "menu.inl"

#endif // MENU_H
