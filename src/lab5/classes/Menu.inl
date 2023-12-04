#include "iostream"

void Menu::top() {
    std::cout << "\t\tMENU Stack-Template\n"
                 "\t1. Push element.\n"
                 "\t2. Top element.\n"
                 "\t3. Pop element.\n"
                 "\t4. Clear stack.\n"
                 "\t5. Show stack.\n"
                 "\t6. Find element.\n"
                 "\t7. Sort.\n"
                 "\t8. Exit.\n";
    std::cin >> choice;
}

void Menu::clear() {
    system("clear");
}

Menu::Menu() {
    choice = -1;
}

Menu::~Menu() = default;

template <typename T>
void Menu::start(Stack<T> &stack) {
    while (choice != 0) {
        clear();
        top();
        if (choice == 1) {
            T element;
            std::cout << "Enter element:\n";
            std::cin >> element;
            stack.push(element);
            std::cout << "Successfully!\n";
            std::cin.get();
            std::cin.get();

            continue;
        }
        else if (choice == 2) {
            std::cout << "The top element:" << stack.top() << std::endl;
            std::cin.get();
            std::cin.get();

            continue;
        }
        else if (choice == 3) {
            stack.pop();
            std::cout << "The element was poped.\n";
            std::cin.get();
            std::cin.get();

            continue;
        }
        else if (choice == 4) {
            stack.clear();
            std::cout << "The stack was cleared\n";
            std::cin.get();
            std::cin.get();

            continue;
        }
        else if (choice == 5) {
                std::cout << stack;
                std::cin.get();
                std::cin.get();

                continue;
        }
        else if (choice == 6) {
            T element;
            std::cout << "Enter the element to find\n";
            std::cin >> element;
            if(stack.find_element(element))
                std::cout << "The element was found\n";
            else
                std::cout << "The element was not found\n";
            std::cin.get();
            std::cin.get();
        }
        else if (choice == 7) {
            stack.sort();
        }if (choice == 8) {
            choice = 0;
        }
    }
}