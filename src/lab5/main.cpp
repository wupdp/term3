#include <iostream>
#include "headers/stack.h"
#include "headers/menu.h"

int main() {
    Stack<std::string> stack_str;
    Menu menu;
    menu.start(stack_str);

    return 0;
}