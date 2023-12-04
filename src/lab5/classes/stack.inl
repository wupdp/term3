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
    try {
        Node<T>* newNode = new Node<T>(value);
        if (newNode == nullptr) {
            throw StackException<T>("Memory allocation failed. Unable to push element onto the stack.");
        }
        newNode->next = top_node;
        top_node = newNode;
    } catch (const StackException<T>& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        throw; // Повторное выбрасывание исключения для обработки на уровне выше
    }
}

template<typename T>
void Stack<T>::pop() {
    try {
        if (!is_empty()) {
            Node<T> *temp = top_node;
            top_node = top_node->next;
            delete temp;
        } else {
            throw StackException<T>("Stack is empty. Cannot pop.");
        }
    } catch (const StackException<T>& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        throw; // Повторное выбрасывание исключения для обработки на уровне выше
    }
}

template<typename T>
T &Stack<T>::top() {
    try {
        if (!is_empty()) {
            return top_node->data;
        } else {
            throw StackException<T>("Stack is empty. Cannot get top.");
        }
    } catch (const StackException<T>& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        throw; // Повторное выбрасывание исключения для обработки на уровне выше
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
void Stack<T>::sort() {
    if (is_empty() || size() == 1) {
        return;
    }

    bool swapped;
    Node<T> *current;
    Node<T> *temp = nullptr;
    do {
        swapped = false;
        current = top_node;

        while (current->next != temp) {
            if (current->data > current->next->data) {
                std::swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
        temp = current;
    } while (swapped);
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