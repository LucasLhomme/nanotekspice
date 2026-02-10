/*
** EPITECH PROJECT, 2026
** nano
** File description:
** Exception
*/

#ifndef NANO_EXCEPTION_HPP
    #define NANO_EXCEPTION_HPP

#include <exception>
#include <iostream>

class FactoryException : public std::exception {
public:
    explicit FactoryException(const std::string &type);
    const char *what() const noexcept override;

private:
    std::string _message;
};

#endif //NANO_EXCEPTION_HPP
