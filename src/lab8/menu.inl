#include "menu.h"

template <typename T>
void Menu<T>::run() {
    while (true) {
        printMainMenu();
        int choice = getUserChoice(1, 3);

        switch (choice) {
            case 1:
                handleCustomStack();
                break;
            case 2:
                handleSTLStack();
                break;
            case 3:
                std::cout << "Exiting the program. Goodbye!" << std::endl;
                return;
            default:
                std::cout << "Invalid choice. Please enter a valid choice." << std::endl;
        }
    }
}

template <typename T>
void Menu<T>::printMainMenu() {
    std::cout << "Main Menu:\n"
              << "1. Custom Stack\n"
              << "2. STL Stack\n"
              << "3. Exit\n"
              << "Enter your choice: ";
}

template <typename T>
int Menu<T>::getUserChoice(int min, int max) {
    int choice;
    while (true) {
        std::cout << "Enter a choice between " << min << " and " << max << ": ";
        if (std::cin >> choice && choice >= min && choice <= max) {
            break;
        } else {
            std::cout << "Invalid input. Please enter a valid choice." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return choice;
}

template <typename T>
void Menu<T>::handleCustomStack() {
    Stack<T> customStack;
    while (true) {
        printCustomStackMenu();
        int choice = getUserChoice(1, 8);

        switch (choice) {
            case 1:
                handlePush(customStack);
                break;
            case 2:
                handlePop(customStack);
                break;
            case 3:
                handleTop(customStack);
                break;
            case 4:
                handleIsEmpty(customStack);
                break;
            case 5:
                handlePrint(customStack);
                break;
            case 6:
                handleCustomStackSort(customStack);
                break;
            case 7:
                handleCustomStackErase(customStack);
                break;
            case 8:
                handleCustomStackInsert(customStack);
                break;
            case 9:
                handleCustomStackContains(customStack);
                break;
            case 10:
                return;
            default:
                std::cout << "Invalid choice. Please enter a valid choice." << std::endl;
        }
    }
}

template <typename T>
void Menu<T>::printCustomStackMenu() {
    std::cout << "Custom Stack Menu:\n"
              << "1. Push\n"
              << "2. Pop\n"
              << "3. Top\n"
              << "4. Is Empty?\n"
              << "5. Print\n"
              << "6. Sort\n"
              << "7. Erase\n"
              << "8. Insert\n"
              << "9. Contains\n"
              << "10. Back to Main Menu\n"
              << "Enter your choice: ";
}

template <typename T>
void Menu<T>::handleSTLStack() {
    std::stack<T> stlStack;
    while (true) {
        printSTLStackMenu();
        int choice = getUserChoice(1, 8);

        switch (choice) {
            case 1:
                handleSTLPush(stlStack);
                break;
            case 2:
                handleSTLPop(stlStack);
                break;
            case 3:
                handleSTLTop(stlStack);
                break;
            case 4:
                handleSTLIsEmpty(stlStack);
                break;
            case 5:
                handleSTLPrint(stlStack);
                break;
            case 6:
                std::cout << "STL Stack Iterator is not available for this example." << std::endl;
                break;
            case 7:
                return;
            default:
                std::cout << "Invalid choice. Please enter a valid choice." << std::endl;
        }
    }
}

template <typename T>
void Menu<T>::printSTLStackMenu() {
    std::cout << "STL Stack Menu:\n"
              << "1. Push\n"
              << "2. Pop\n"
              << "3. Top\n"
              << "4. Is Empty\n"
              << "5. Print\n"
              << "6. STL Stack Iterator (Not Available)\n"
              << "7. Back to Main Menu\n"
              << "Enter your choice: ";
}

template <typename T>
void Menu<T>::handlePush(Stack<T>& stack) {
    T value;
    std::cout << "Enter value to push: ";
    std::cin >> value;
    stack.push(value);
    std::cout << "Pushed element " << value << " to the stack." << std::endl;
}

template <typename T>
void Menu<T>::handlePop(Stack<T>& stack) {
    if (!stack.is_empty()) {
        T value = stack.top();
        stack.pop();
        std::cout << "Popped element " << value << " from the stack." << std::endl;
    } else {
        std::cout << "Stack is empty. Cannot pop." << std::endl;
    }
}

template <typename T>
void Menu<T>::handleTop(Stack<T>& stack) {
    try {
        std::cout << "Top element: " << stack.top() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }
}

template <typename T>
void Menu<T>::handleIsEmpty(const Stack<T>& stack) {
    if (stack.is_empty()) {
        std::cout << "Stack is empty." << std::endl;
    } else {
        std::cout << "Stack is not empty." << std::endl;
    }
}

template <typename T>
void Menu<T>::handlePrint(const Stack<T>& stack) {
    std::cout << "Stack: " << stack << std::endl;
}

template <typename T>
void Menu<T>::handleCustomStackErase(Stack<T>& stack) {
    T element;
    std::cout << "Enter element to erase: ";
    std::cin >> element;

    if (stack.find_element(element)) {
        stack.erase(element);
        std::cout << "Element " << element << " erased from Custom Stack." << std::endl;
    } else {
        std::cout << "Element not found in Custom Stack." << std::endl;
    }
}

template <typename T>
void Menu<T>::handleCustomStackInsert(Stack<T>& stack) {
    T element;
    std::cout << "Enter element to insert: ";
    std::cin >> element;

    stack.insert(element);
    std::cout << "Element " << element << " inserted into Custom Stack." << std::endl;
}

template <typename T>
void Menu<T>::handleCustomStackContains(const Stack<T>& stack) {
    T element;
    std::cout << "Enter element to check: ";
    std::cin >> element;

    if (stack.contains(element)) {
        std::cout << "Custom Stack contains element " << element << "." << std::endl;
    } else {
        std::cout << "Custom Stack does not contain element " << element << "." << std::endl;
    }
}

template <typename T>
void Menu<T>::handleCustomStackSort(Stack<T>& stack) {
    stack.sort();
    std::cout << "Custom Stack sorted." << std::endl;
}

template <typename T>
void Menu<T>::handleSTLPush(std::stack<T>& stack) {
    T value;
    std::cout << "Enter value to push: ";
    std::cin >> value;
    stack.push(value);
    std::cout << "Pushed element " << value << " to the stack." << std::endl;
}

template <typename T>
void Menu<T>::handleSTLPop(std::stack<T>& stack) {
    if (!stack.empty()) {
        T value = stack.top();
        stack.pop();
        std::cout << "Popped element " << value << " from the stack." << std::endl;
    } else {
        std::cout << "STL Stack is empty. Cannot pop." << std::endl;
    }
}

template <typename T>
void Menu<T>::handleSTLTop(const std::stack<T>& stack) {
    if (!stack.empty()) {
        std::cout << "Top element: " << stack.top() << std::endl;
    } else {
        std::cout << "STL Stack is empty. Cannot get top." << std::endl;
    }
}

template <typename T>
void Menu<T>::handleSTLIsEmpty(const std::stack<T>& stack) {
    if (stack.empty()) {
        std::cout << "STL Stack is empty." << std::endl;
    } else {
        std::cout << "STL Stack is not empty." << std::endl;
    }
}

template <typename T>
void Menu<T>::handleSTLPrint(const std::stack<T>& stack) {
    std::stack<T> tempStack = stack;
    std::cout << "STL Stack: ";
    while (!tempStack.empty()) {
        std::cout << tempStack.top() << " ";
        tempStack.pop();
    }
    std::cout << std::endl;
}