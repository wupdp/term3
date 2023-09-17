#include "massive.h"

using namespace std;

Massive::Massive() {
    count = 0;
    elements = nullptr;
}

Massive::Massive(int num) {
    count = num;
    elements = new int[num];
    for (int i = 0; i < count; i++)
        elements[i] = 0;
}

Massive::Massive(const Massive &other) {
    count = other.count;
    elements = new int[count];
    for (int i = 0; i < count; i++)
        elements[i] = other.elements[i];
}

Massive &Massive::operator=(const Massive &other) noexcept {
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

Massive::~Massive() {
    delete[] elements;
    count = -1;
}

void Massive::show() {
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

void Massive::show(int num) {
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

void Massive::enter() {
    if (elements == nullptr) {
        cout << "Massive is empty\n";
        return;
    }
    for (int i = 0; i < count; i++) {
        cout << "Enter the " << i << " element: ";
        cin >> elements[i];
    }
}

void Massive::enter(int num) {
    if (elements == nullptr) {
        cout << "Massive is empty\n";
        return;
    }
    if (num != count) {
        int *new_data = new int[num];
        for (int i = 0; i < count && i < num; i++)
            new_data[i] = elements[i];
        delete[] elements;
        elements = new_data;
        count = num;
    }

    for (int i = 0; i < num; i++) {
        cout << "Enter the " << i << " element: ";
        cin >> elements[i];
    }
}

void Massive::add(int num) {
    int *new_data = new int[count + 1];

    for (int i = 0; i < count; i++)
        new_data[i] = elements[i];
    new_data[count] = num;
    count++;
    delete[] elements;
    elements = new_data;
}

void Massive::crossing(Massive &mas1, Massive &mas2) {
    if (mas1.elements == nullptr || mas2.elements == nullptr) {
        cout << "One of the massive is empty\n";
        return;
    }

    delete[] elements;

    elements = new int[mas1.count];
    count = 0;

    for (int i = 0; i < mas1.count && i < mas2.count; i++) {
        if (mas1.elements[i] == mas2.elements[i]) {
            elements[count] = mas1.elements[i];
            count++;
        }
    }

    int *new_mas;
    new_mas = new int[count];

    for (int j = 0; j < count; j++)
        new_mas[j] = elements[j];

    delete[] elements;
    elements = new_mas;
}
