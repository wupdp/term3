#include <limits>
void Interface() {
    while (1) {
        system("clear");
        std::cout << "�������� ��������" << std::endl;
        int choice;
        std::cout << "1. ��������� ���� ����� ������ Teacher (InputException)" << std::endl
            << "2. ��������� �������� ����� (FileException)" << std::endl
            << "0. �����" << std::endl;
        std::cout << "��� �����: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (choice) {
        case 1: {
            system("clear");
            PartyTeacher pteacher;
            std::cin >> pteacher;
            Teacher::head();
            std::cout << pteacher << std::endl;
            break;
        }
        case 2: {
            system("clear");

            std::string file_name;
            std::cout << "������� �������� �����: ";
            std::cin.ignore();
            std::getline(std::cin, file_name);

            try {
                check_file_exist(file_name.data());
                check_file_empty(file_name.data());
                check_file_open(file_name.data());
                }
            catch (FileException& e) {
                e.what_file();
            }
            break;
        }
        case 0:
            return;
        default:
            std::cout << "������!" << std::endl;
            break;
        }
    }
}
