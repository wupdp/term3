#include <iostream>

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
T &Stack<T>::top() {
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