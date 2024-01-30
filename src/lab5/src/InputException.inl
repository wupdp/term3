#include <limits>
InputException::InputException(int input_сode, std::string first_msg, std::string second_msg)
    : Exception(input_сode, first_msg) {
    input_msg = second_msg;
}

InputException::~InputException() {}

void InputException::whatInput() {

    this->what();
    std::cout << input_msg << '\n';
}

std::string input_str(std::istream& is) {
    std::string str;
    bool flag = true;

    do {
        flag = true;
        try {
            std::getline(is, str);

            if (str.empty()) {
                throw InputException(5, "String input error!", "You haven't entered string!");
            }

            for (char c : str) {
                if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '�' && c <= '�') || (c >= '�' && c <= '�'))) {
                    throw InputException(3, "String input error!", "Use only latin or cyrillic symbols!");
                }
            }
        }
        catch (InputException& obj) {
            std::cin.clear();
            obj.what_input();
            flag = false;
        }
    } while (!flag);

    return str;
}

int input_int(std::istream& is, int min, int max) {
    int num;
    bool flag = true;
    do {
        flag = true;
        try {
            rewind(stdin);
            is >> num;
            if (is.fail() || std::cin.peek() != '\n') {
                throw InputException(1, "Number input error!", "You entered a character, enter numbers!");
            }
            if (num < min || num > max) {
                throw InputException(4, "Number input error!", "Number out of range!");
            }
        }
        catch (InputException& obj) {
            std::cin.clear();
            obj.what_input();
            flag = false;
        }
    } while (!flag);

    return num;
}

int input_int(std::istream& is) {
    int num;
    bool flag = true;
    do {
        flag = true;
        try {
            rewind(stdin);
            is >> num;

            if (is.fail() || std::cin.peek() != '\n') {
                throw InputException(1, "Number input error!", "You entered not a number!");
            }
        }
        catch (InputException& obj) {
            std::cin.clear();
            obj.what_input();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            flag = false;
        }
    } while (!flag);

    return num;
}