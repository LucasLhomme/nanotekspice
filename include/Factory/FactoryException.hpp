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

namespace nts {
    class FactoryException : public std::exception {
        private:
            std::string _message;
        public:
            explicit FactoryException(const std::string &type);
            const char *what() const noexcept override;
    };
}

#endif //NANO_EXCEPTION_HPP
