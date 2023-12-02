#include "iostream"

void Menu::top() {
    std::cout << "\t\tMENU Stack-String\n"
                 "\t1. Push string.\n"
                 "\t2. Top string.\n"
                 "\t3. Pop string.\n"
                 "\t4. Clear stack.\n"
                 "\t5. Clear and show stack.\n"
                 "\t6. Find element.\n"
                 "\t7. Exit.\n";
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
            T str;
            std::cout << "Enter element:\n";
            std::cin >> str;
            stack.push(str);
            std::cout << "Successfully!\n";
            std::cin.get();
            std::cin.get();

            continue;
        }
        if (choice == 2) {
            if (stack.is_empty() == 1) {
                std::cout << "The stack is empty\n";
                std::cin.get();
                std::cin.get();
                continue;
            }
            std::cout << "The top element:" << stack.top() << std::endl;
            std::cin.get();
            std::cin.get();

            continue;
        }
        if (choice == 3) {
            if (stack.is_empty() == 1) {
                std::cout << "The stack is empty\n";
                std::cin.get();
                std::cin.get();
                continue;
            }
            stack.pop();
            std::cout << "The element was poped.\n";
            std::cin.get();
            std::cin.get();

            continue;
        }
        if (choice == 4) {
            if (stack.is_empty() == 1) {
                std::cout << "The stack is empty\n";
                std::cin.get();
                std::cin.get();
                continue;
            }
            stack.clear();
            std::cout << "The stack was cleared\n";
            std::cin.get();
            std::cin.get();

            continue;
        }
        if (choice == 5) {
            if (stack.is_empty() == 1) {
                std::cout << "The stack is empty\n";
                std::cin.get();
                std::cin.get();
                continue;
            }
            while (stack.is_empty() == 0) {
                std::cout << stack.top() << std::endl;
                stack.pop();
            }
            stack.clear();
            std::cout << "The stack was cleared\n";
            std::cin.get();
            std::cin.get();

            continue;
        }
        if (choice == 6) {
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
        if (choice == 7) {
            choice = 0;
        }
    }
}