#include "headers/menu_functions.h"

void menu() {

    char ch;
    int num_of_mas = 0;
    Massive *mas = nullptr;

    while (ch != 'q') {                     //Цикл меню
        cout << "\t\tMENU\n"
                "\tEnter the choice\n"
                "\t1. Create massive\n"
                "\t2. Enter/rewrite the massive\n"
                "\t3. Show massive\n"
                "\t4. Add number to the massive\n"
                "\t5. Delete the massive\n"
                "\t6. Cross the massives\n";
        cin >> ch;
        if (ch == 'q') {
            break;
        }
        if (ch >= 49 && ch <= 54) {
            options(ch, mas, num_of_mas);
        }
    }
    system("clear");
}

void options(char ch, Massive *&mas, int &num_of_mas) {         //Опции меню
    if (ch == '1') {
        cout << "Enter the count of new massive\n";
        int count;
        cin >> count;

        Massive obj(count);
        Massive *new_mas;
        new_mas = new Massive[num_of_mas + 1];

        for (int i = 0; i < num_of_mas; i++)
            new_mas[i] = mas[i];

        new_mas[num_of_mas] = obj;
        delete[] mas;
        mas = new_mas;

        num_of_mas++;

        return;
    }

    int ch2, ch3, ch4;

    if (ch == '6') {
        Massive obj, obj1(5), obj2(5);

        obj1.enter();
        obj2.enter();

        /*cout << "Enter the masssives you want to cross:\n";
        cin >> ch3 >> ch2;*/
       /* if (ch2 > num_of_mas || ch3 > num_of_mas) {
            cout << "No such massive, please retry\n";
            return;
        }*/

        obj.crossing(obj1, obj2);

        Massive *new_mas;
        new_mas = new Massive[num_of_mas + 1];

        for (int i = 0; i < num_of_mas; i++)
            new_mas[i] = mas[i];

        new_mas[num_of_mas] = obj;

        delete[] mas;
        mas = new_mas;

        num_of_mas++;
/*
        cout << "Enter the 3th masssive you want to cross:\n";
        cin >> ch4;

        obj.crossing(mas[ch4 - 1], mas[num_of_mas - 1]);
        mas[num_of_mas - 1] = obj;
*/
       // cout << "Crossed massives:\n";
       // mas[ch2 - 1].show();
       // mas[ch3 - 1].show();
       // mas[ch4 - 1].show();
        mas[num_of_mas - 1] = obj;
        cout << endl;
        cout << "The crossing mas now is number " << num_of_mas << ":\n";
        mas[num_of_mas - 1].show();
        cout << endl;

        return;
    }

    cout << "Enter the number of massive you want to work with:\n";
    cin >> ch2;

    if (ch2 < 1 || ch2 > num_of_mas) {
        cout << "There are no such a massive\n";

        return;
    }

    if (ch == '2') {
        cout << "Do you want to change the size??\n"
                "Yes - enter the size\n"
                "No - enter 0\n";
        cin >> ch3;

        if (ch3 == 0) {
            mas[ch2 - 1].enter();
        }

        if (ch3 > 0) {
            mas[ch2 - 1].enter(ch3);
        }
        return;
    }
    if (ch == '3') {
        cout << "Enter how much elements you want to see?\n"
                "All - enter 0\n";
        cin >> ch3;

        if (ch3 == 0)
            mas[ch2 - 1].show();

        if (ch3 > 0)
            mas[ch2 - 1].show(ch3);

        return;
    }
    if (ch == '4') {
        cout << "Enter the number you want to add:\n";
        cin >> ch3;

        mas[ch2 - 1].add(ch3);

        return;
    }
    if (ch == '5') {
        Massive *new_mas;
        new_mas = new Massive[num_of_mas - 1];

        for (int i = 0, j = 0; i < num_of_mas; j++, i++) {
            if (i == ch2 - 1) i++;

            if (i < num_of_mas) {
                new_mas[j] = mas[i];
            }
        }

        delete[] mas;
        mas = new_mas;

        num_of_mas--;
    }
}