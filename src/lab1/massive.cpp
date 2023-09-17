#include "massive.h"

using namespace std;

massive_class::massive_class() {
    count = 0;
    elements = nullptr;
}

massive_class::massive_class(int num) {
    count = num;
    elements = new int[num];
}

massive_class::~massive_class() {
    delete[] elements;
}

void massive_class::show() {
    if (elements == nullptr) {
        cout << "Massive is empty\n";
        return;
    }
    for (int i = 0; i < count; i++) {
        cout << elements[i] << endl;
    }
}

void massive_class::show(int num) {
    if (elements == nullptr) {
        cout << "Massive is empty\n";
        return;
    }
    for (int i = 0; i < count && i < num; i++) {
        cout << elements[i] << endl;
    }
}

void massive_class::enter() {
    if (elements == nullptr) {
        cout << "Massive is empty\n";
        return;
    }
    for (int i = 0; i < count; i++) {
        cin >> elements[i];
    }
}

void massive_class::enter(int num) {
    if (elements == nullptr) {
        cout << "Massive is empty\n";
        return;
    }
    for (int i = 0; i < num; i++) {
        cin >> elements[i];
    }
}

void massive_class::add(int num) {
    int element;
    int *new_data = new int[++count];

    cout << "Enter the element\n";
    cin >> element;

    if (elements == nullptr) {
        elements = new_data;
        return;
    }

    for (int i = 0; i < count - 1; i++)
        new_data[i] = elements[i];
    elements[count - 1] = element;

    delete[] new_data;
}

void massive_class::crossing(massive_class &mas1, massive_class &mas2) {
    if(mas1.elements == nullptr || mas2.elements == nullptr){
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
