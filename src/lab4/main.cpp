#include <iostream>
#include "headers/stack.h"

int main() {
    Stack<int> stack;
    if (stack.is_empty())
        std::cout << "Stack is empty\n";
    stack.push(0);
    stack.push(-34);
    stack.push(556);
    stack.push(776);
    if (!stack.is_empty())
        std::cout << "Size: " <<stack.size() << std::endl;
    if (!stack.is_empty())
        std::cout << "Top data: " << stack.top() << std::endl;
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    std::cout << "Size: " << stack.size() << std::endl;

    return 0;
}
