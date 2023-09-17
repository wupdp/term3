#include "menu_functions.h"

void menu() {

    char ch;
    int num_of_mas = 0;
    Massive *mas = nullptr;

    while (ch != 'q') {
        system("clear");
        cout << "\t\tMENU\n"
                "\tEnter the choice\n"
                "\t1. Create massive\n"
                "\t2. Enter/rewrite the massive\n"
                "\t3. Show massive\n"
                "\t4. Add number to the massive\n"
                "\t5. Delete the massive\n"
                "\t6. Cross the massives\n";
        cin >> ch;
        if (ch == 'q')
            break;
        if (ch >= 49 && ch <= 54)
            options(ch, mas, num_of_mas);
    }
}

void options(char ch, Massive *&mas, int &num_of_mas) {
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

    int ch2, ch3;

    if (ch == '6') {
        Massive obj;
        cout << "Enter the masssives you want to cross:\n";
        cin >> ch3 >> ch2;

        obj.crossing(mas[ch3 - 1], mas[ch2 - 1]);

        Massive *new_mas;
        new_mas = new Massive[num_of_mas + 1];

        for (int i = 0; i < num_of_mas; i++)
            new_mas[i] = mas[i];

        new_mas[num_of_mas] = obj;
        delete[] mas;
        mas = new_mas;
        num_of_mas++;
        cout << "Crossed massives:\n";
        mas[ch2 - 1].show();
        mas[ch3 - 1].show();
        cout << "The crossing mas now is number " << num_of_mas << ":\n";
        mas[num_of_mas - 1].show();

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
        if (ch3 == 0) {
            mas[ch2 - 1].show();
        }
        if (ch3 > 0) {
            mas[ch2 - 1].show(ch3);
        }
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