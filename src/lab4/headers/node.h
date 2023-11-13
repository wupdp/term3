#pragma once

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    Node(const T& value) : data(value), next(nullptr) {}
};
