#include "menu_functions.h"

void menu() {
    system("clear");
    char ch;
    int num_of_mas = 0;
    massive_class *mas = nullptr;

    while (ch != 'q') {
        cout
                << "\t\tMENU\n\tEnter the choice\n\t1. Create massive\n\t2. Enter/rewrite the massive\n\t3. Show massive\n\t4. Add number to the massive\n"
                   "\t5. Delete the massive\n";
        cin >> ch;
        if (ch == 'q')
            break;
        if (ch >= 49 && ch <= 53)
            options(ch, mas, num_of_mas);
    }
}

void options(char ch, massive_class *mas, int &num_of_mas) {
    if (ch == '1') {
        cout << "Enter the count of new massive\n";
        int count;
        cin >> count;
        massive_class obj(count);

        auto *new_mas = new massive_class[++num_of_mas];

        for (int i = 0; i < num_of_mas - 1; i++)
            new_mas[i] = mas[i];
        new_mas[num_of_mas - 1] = obj;
        mas = new_mas;

        return;
    }
    if (ch == '2') {
        return;
    }
    if (ch == '3') {
        return;
    }
    if (ch == '4') {
        return;
    }
    if (ch == '5') {
        return;
    }
}