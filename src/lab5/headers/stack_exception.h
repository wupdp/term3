#pragma once
#include <stdexcept>

enum class StackErrorType {
    EMPTY_STACK,
    MEMORY_ALLOCATION_FAILED,
    INVALID_OPERATION
};

template <typename T>
class StackException : public std::exception {
private:
    std::string message;
    StackErrorType error_type;

public:
    explicit StackException(StackErrorType type);
    [[nodiscard]] const char* what() const noexcept override;
};

#include "../classes/stack_exception.inl"