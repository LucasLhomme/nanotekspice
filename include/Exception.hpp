/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Exception
*/

#ifndef NANO_1_EXCEPTION_HPP
#define NANO_1_EXCEPTION_HPP

#include <exception>
#include <string>

class Exception : public std::exception {
    private:
        std::string _message;
    public:
        explicit Exception(const std::string &message) : _message(message) {}
        const char* what() const noexcept override {
            return _message.c_str();
        }
};

#endif //NANO_1_EXCEPTION_HPP