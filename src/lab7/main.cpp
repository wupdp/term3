#include <iostream>
#include "headers/stack.h"

int main() {
    Stack<int> stack;

    stack.push(5);
    stack.push(2);
    stack.push(8);
    stack.push(1);
    stack.push(7);

    std::cout << "Stack after push: " << stack << std::endl;

    auto it = stack.begin();
    ++it; 
    stack.insert(it, 10);
    std::cout << "Stack after insert: " << stack << std::endl;

    it = stack.begin();
    ++it;
    stack.erase(it);
    std::cout << "Stack after erase: " << stack << std::endl;

    int elementToFind = 8;
    if (stack.contains(elementToFind)) {
        std::cout << "Stack contains element " << elementToFind << std::endl;
    } else {
        std::cout << "Stack does not contain element " << elementToFind << std::endl;
    }

    stack.sort();
    std::cout << "Stack after sort: " << stack << std::endl;

    return 0;
}