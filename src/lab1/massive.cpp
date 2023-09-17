#include "massive.h"
#include <iostream>

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
    for (int i = 0; i < count; i++) {
        cout << elements[i] << endl;
    }
}

void massive_class::show(int num) {
    for (int i = 0; i < count && i < num; i++) {
        cout << elements[i] << endl;
    }
}

void massive_class::enter() {
    for (int i = 0; i < count; i++) {
        cin >> elements[i];
    }
}

void massive_class::enter(int num) {
    for (int i = 0; i < num; i++) {
        cin >> elements[i];
    }
}

void massive_class::add(int num) {
    elements[count] = num;
}

void massive_class::crossing(massive_class &mas1, massive_class &mas2) {
    for (int i = 0; i < mas1.count; i++) {
        for (int j = 0; j < mas2.count; j++) {
            if (mas1.elements[i] == mas2.elements[j])
                elements[i] = mas1.elements[i];
        }
    }
}

void menu(){

}
//