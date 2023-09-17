#include "massive.h"

using namespace std;

massive_class::massive_class() {
    count = 0;
    elements = nullptr;
}

massive_class::massive_class(int num) {
    count = num;
    elements = new int[num];
    for (int i = 0; i < count; i++)
        elements[i] = 0;
}

massive_class::massive_class(const massive_class &other) {
    count = other.count;
    elements = new int[count];
    for (int i = 0; i < count; i++)
        elements[i] = other.elements[i];
}

massive_class &massive_class::operator=(const massive_class &other) noexcept {
    if (this == &other) {
        return *this;
    }

    delete[] elements;

    count = other.count;
    elements = new int[count];
    for (int i = 0; i < count; i++) {
        elements[i] = other.elements[i];
    }

    return *this;
}

massive_class::~massive_class() {
    delete[] elements;
    count = -1;
}

void massive_class::show() {
    if (elements == nullptr) {
        cout << "Massive is empty\n";
        return;
    }

    cout << "Massive:\n";
    for (int i = 0; i < count; i++) {
        cout << elements[i] << " ";
    }
    cout << endl;
}

void massive_class::show(int num) {
    if (elements == nullptr) {
        cout << "Massive is empty\n";
        return;
    }
    cout << "First " << num << " elements:\n";
    for (int i = 0; i < count && i < num; i++) {
        cout << elements[i] << " ";
    }
    cout << endl;
}

void massive_class::enter() {
    if (elements == nullptr) {
        cout << "Massive is empty\n";
        return;
    }
    for (int i = 0; i < count; i++) {
        cout << "Enter the " << i << " element: ";
        cin >> elements[i];
    }
}

void massive_class::enter(int num) {
    if (elements == nullptr) {
        cout << "Massive is empty\n";
        return;
    }
    if (num != count) {
        int *new_data = new int[num];
        for (int i = 0; i < count && i < num; i++)
            new_data[i] = elements[i];
        elements = new_data;
        delete[] new_data;
        count = num;
    }

    for (int i = 0; i < num; i++) {
        cout << "Enter the " << i << " element: ";
        cin >> elements[i];
    }
}

void massive_class::add(int num) {
    int *new_data = new int[++count];

    if (elements == nullptr) {
        new_data[0] = num;
        elements = new_data;
        delete[] new_data;
        return;
    }

    for (int i = 0; i < count - 1; i++)
        new_data[i] = elements[i];
    new_data[count - 1] = num;

    elements = new_data;
    delete[] new_data;
}

void massive_class::crossing(massive_class &mas1, massive_class &mas2) {
    if (mas1.elements == nullptr || mas2.elements == nullptr) {
        cout << "One of the massive is empty\n";
        return;
    }

    for (int i = 0; i < mas1.count; i++) {
        for (int j = 0; j < mas2.count; j++) {
            if (mas1.elements[i] == mas2.elements[j])
                elements[i] = mas1.elements[i];
        }
    }
}
