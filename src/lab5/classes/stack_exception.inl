#include "../headers/stack_exception.h"

template <typename T>
StackException<T>::StackException(StackErrorType type) : error_type(type) {
    switch (error_type) {
        case StackErrorType::EMPTY_STACK:
            message = "Stack is empty. Cannot perform operation.";
            break;
        case StackErrorType::MEMORY_ALLOCATION_FAILED:
            message = "Memory allocation failed. Unable to perform operation.";
            break;
        case StackErrorType::INVALID_OPERATION:
            message = "Invalid operation on the stack.";
            break;
        default:
            message = "Unknown error occurred.";
            break;
    }
}

template <typename T>
const char* StackException<T>::what() const noexcept {
    return message.c_str();
}