#include "../headers/String.h"
using namespace std;
int main(){
    String str1, str2, result_str;
    String str3("Test string for presentation");

    cout << "Введите первую строку" << endl;
    cin >> str1;
    cout << "Введите вторую строку" << endl;
    cin >> str2;
    getchar();

    cout << "++str1 + str2\n";
    result_str = "sedgresg" + ++str1 + str2+"250501";
    cout << result_str << endl;
    getchar();

    cout << "+= str3\n";
    result_str += str3;
    cout << result_str << endl;
    getchar();

    result_str--;
    --result_str;
    cout << "str--;\n"
            "--str\n";
    cout << result_str << endl;
    getchar();

    result_str++;
    ++result_str;
    cout << "str++\n"
            "++str\n";
    cout << result_str << endl;
    getchar();

    if (str1 > str2) {
        cout << "Первая строка больше второй\n";
    }
    else if (str1 < str2) {
        cout << "Первая строка меньше второй\n";
    }
    else {
        cout << "Строки имеют равный размер\n";
    }
    getchar();

    result_str = str3.substring(7, 11);
    cout << "str3.substring(7, 11)\n";
    cout << result_str << endl;
    getchar();

    return 0;
}