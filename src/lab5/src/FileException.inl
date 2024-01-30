FileException::FileException(int input_code, std::string first_massage, std::string second_massage)
    : Exception(input_code, first_massage)
{
    file_msg = second_massage;
};

FileException::~FileException() {

};

void FileException::whatFile() {

    this->what();
    std::cout << file_msg << '\n';
};

void check_file_exist(const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw FileException(1, "File doesn't exist!", "File was not found!");
    }
}

void check_file_empty(const char* filename) {
    std::ifstream file(filename);
    if (file.peek() == std::ifstream::traits_type::eof()) {
        throw FileException(2, "File is empty!", "File is empty!");
    }
}

void check_file_open(const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw FileException(3, "File was not opened!", "Failed to open file!");
    }
}
