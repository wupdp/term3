#pragma once

template <typename T>
class Node {
public:
    T data;
    Node* next;

    explicit Node(const T& value) : data(value), next(nullptr) {}
};
