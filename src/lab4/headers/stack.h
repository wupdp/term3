#pragma once
#include <iostream>
#include "node.h"

template <typename T>
class Stack {
private:
    Node<T> *top_node;
public:
    Stack();

    ~Stack();

    void push(const T &value);

    void pop();

    T &top();

    [[nodiscard]] bool is_empty() const;

    [[nodiscard]] size_t size() const;

};