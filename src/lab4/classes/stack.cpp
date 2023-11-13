#include "../headers/stack.h"
#include <iostream>

// Реализация методов класса Stack

#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnreachableCode"
template <typename T>
Stack<T>::Stack() : top_node(nullptr) {}

template <typename T>
Stack<T>::~Stack() {
    while (!is_empty()) {
        pop();
    }
}

template <typename T>
void Stack<T>::push(const T& value) {
    auto newNode = new Node<T>(value);
    newNode->next = top_node;
    top_node = newNode;
}

template <typename T>
void Stack<T>::pop() {
    if (!is_empty()) {
        Node<T>* temp = top_node;
        top_node = top_node->next;
        delete temp;  // Don't forget to delete the node to avoid memory leaks
    } else {
        std::cerr << "Stack is empty. Cannot pop." << std::endl;
    }
}

template <typename T>
T& Stack<T>::top() {
    if (!is_empty()) {
        return top_node->data;
    } else {
        throw std::out_of_range("Stack is empty. Cannot get top.");
    }
}

template <typename T>
[[nodiscard]] bool Stack<T>::is_empty() const {
    return top_node == nullptr;
}

template <typename T>
size_t Stack<T>::size() const {
    size_t count = 0;
    Node<T>* current = top_node;
    while (current != nullptr) {
        ++count;
        current = current->next;
    }
    return count;
}

template class Stack<int>;
template class Stack<char>;
template class Stack<std::string>;
template class Stack<bool>;