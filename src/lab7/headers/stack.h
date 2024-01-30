#pragma once
#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    explicit Node(T data) : data(data), next(nullptr) {}
};

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
    void clear();
    [[nodiscard]] bool is_empty() const;
    [[nodiscard]] size_t size() const;
    bool find_element(T element);
    void sort();

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Stack<U>& stack);
    
    class Iterator {
    private:
        Node<T>* current;

    public:
        Iterator(Node<T>* node) : current(node) {}

        Iterator& operator++() {
            current = current->next;
            return *this;
        }

        T& operator*() {
            return current->data;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
        void insert(const T &value);

        void erase();
    };

    Iterator begin() {
        return Iterator(top_node);
    }

    Iterator end() {
        return Iterator(nullptr);
    }

    void insert(Iterator pos, const T& value);
    void erase(Iterator pos);

    bool contains(const T& value) const;
    void sort();
};

#include "../classes/stack.inl"
