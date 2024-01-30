#include <iostream>
#include "stack.h"

template<typename T>
Stack<T>::Stack() : top_node(nullptr) {}

template<typename T>
Stack<T>::~Stack() {
    while (!is_empty()) {
        pop();
    }
}

template<typename T>
void Stack<T>::push(const T &value) {
    auto newNode = new Node<T>(value);
    newNode->next = top_node;
    top_node = newNode;
}

template<typename T>
void Stack<T>::pop() {
    if (!is_empty()) {
        Node<T> *temp = top_node;
        top_node = top_node->next;
        delete temp;
    } else {
        std::cerr << "Stack is empty. Cannot pop." << std::endl;
    }
}

template<typename T>
T& Stack<T>::top() {
    if (!is_empty()) {
        return top_node->data;
    } else {
        throw std::out_of_range("Stack is empty. Cannot get top.");
    }
}

template<typename T>
[[nodiscard]] bool Stack<T>::is_empty() const {
    return top_node == nullptr;
}

template<typename T>
size_t Stack<T>::size() const {
    size_t count = 0;
    Node<T> *current = top_node;
    while (current != nullptr) {
        ++count;
        current = current->next;
    }
    return count;
}

template<typename T>
void Stack<T>::clear() {
    while (!is_empty()) {
        pop();
    }
}

template<typename T>
bool Stack<T>::find_element(T element) {
    Node<T> *node = top_node;
    while (node != NULL) {
        if (node->data == element)
            return true;
        node = node->next;
    }
    return false;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const Stack<T> &stack) {
    Node<T> *current = stack.top_node;

    while (current != nullptr) {
        os << current->data << " ";
        current = current->next;
    }

    return os;
}

// Добавление элемента по позиции итератора
template<typename T>
void Stack<T>::insert(Iterator pos, const T& value) {
    Node<T>* newNode = new Node<T>(value);
    if (pos.current == nullptr) {
        // Вставка в конец
        push(value);
    } else {
        newNode->next = pos.current->next;
        pos.current->next = newNode;
    }
}

// Удаление элемента по позиции итератора
template<typename T>
void Stack<T>::erase(Iterator pos) {
    if (pos.current == nullptr) {
        // Некорректная позиция
        return;
    }

    Node<T>* temp = pos.current->next;
    if (temp != nullptr) {
        pos.current->next = temp->next;
        delete temp;
    }
}

// Поиск элемента в стеке
template<typename T>
bool Stack<T>::contains(const T& value) const {
    Node<T>* current = top_node;
    while (current != nullptr) {
        if (current->data == value)
            return true;
        current = current->next;
    }
    return false;
}

template<typename T>
void Stack<T>::Iterator::insert(const T& value) {
    Stack<T>::insert(*this, value);
}

template<typename T>
void Stack<T>::Iterator::erase() {
    Stack<T>::erase(*this);
}

// Сортировка стека
template<typename T>
void Stack<T>::sort() {
    if (is_empty() || size() == 1) {
        return;
    }

    Stack<T> tempStack;
    while (!is_empty()) {
        T temp = top();
        pop();

        while (!tempStack.is_empty() && tempStack.top() > temp) {
            push(tempStack.top());
            tempStack.pop();
        }

        tempStack.push(temp);
    }

    while (!tempStack.is_empty()) {
        push(tempStack.top());
        tempStack.pop();
    }
}

