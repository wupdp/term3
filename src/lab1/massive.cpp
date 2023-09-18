#include "massive.h"

using namespace std;

Massive::Massive() {           //Конструктор
    count = 0;
    elements = nullptr;
}

Massive::Massive(int num) {     //Перегрузка конструктора
    count = num;
    elements = new int[num];

    for (int i = 0; i < count; i++)
        elements[i] = 0;
}

Massive::Massive(const Massive &other) {    //Конструктор копирования
    count = other.count;
    elements = new int[count];

    for (int i = 0; i < count; i++)
        elements[i] = other.elements[i];
}

Massive &Massive::operator=(const Massive &other) noexcept {    //Оператор присваивания
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

Massive::~Massive() {       //Деструктор
    delete[] elements;
    count = 0;
}

void Massive::show() {              //Вывод массива на экран
    if (elements == nullptr) {
        cout << "Massive is empty\n";      //Проверка на пустой массив

        return;
    }

    cout << "Massive:\n";

    for (int i = 0; i < count; i++) {
        cout << elements[i] << " ";
    }
    cout << endl;
}

void Massive::show(int num) {       //Вывод первых num символов на экран
    if (elements == nullptr) {
        cout << "Massive is empty\n";   //Проверка на пустой массив

        return;
    }
    cout << "First " << num << " elements:\n";

    for (int i = 0; i < count && i < num; i++) {
        cout << elements[i] << " ";
    }
    cout << endl;
}

void Massive::enter() {             //Ввод элемнтов массива
    if (elements == nullptr) {
        cout << "Massive is empty\n";       //Проверка на пустой массив

        return;
    }

    for (int i = 0; i < count; i++) {
        cout << "Enter the " << i << " element: ";
        cin >> elements[i];
    }
}

void Massive::enter(int num) {          //Ввод первых num элементов в массив с переопределением памяти
    if (elements == nullptr) {
        cout << "Massive is empty\n";

        return;
    }

    if (num != count) {                 //Проверка на новый размер массива
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

void Massive::add(int num) {                //Добавление нового элемента в массив
    int *new_data = new int[count + 1];

    for (int i = 0; i < count; i++)
        new_data[i] = elements[i];

    new_data[count] = num;
    count++;

    delete[] elements;
    elements = new_data;
}

void Massive::crossing(Massive &mas1, Massive &mas2) {              //Пересечение двух массивов
    if (mas1.elements == nullptr || mas2.elements == nullptr) {
        cout << "One of the massive is empty\n";                    //Проверка на пустой массив

        return;
    }

    delete[] elements;

    elements = new int[mas1.count];
    count = 0;

    sort(mas1.elements, mas1.elements + mas1.count);        //Сортировка массивов
    sort(mas2.elements, mas2.elements + mas2.count);

    int i = 0;
    int j = 0;

    while (i < mas1.count && j < mas2.count) {                      //Создание массива пересечения
        if (mas1.elements[i] < mas2.elements[j])
            i++;
        else if (mas1.elements[i] > mas2.elements[j])
            j++;
        else {
            elements[count] = mas1.elements[i];
            count++;
            i++;
            j++;
        }
    }

    int *new_mas;
    new_mas = new int[count];

    for (int k = 0; k < count; k++)
        new_mas[k] = elements[k];

    delete[] elements;
    elements = new_mas;
}
