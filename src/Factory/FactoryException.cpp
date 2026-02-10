/*
** EPITECH PROJECT, 2026
** nano
** File description:
** UnknowTypeException
*/
#include "Exception/FactoryException.hpp"

FactoryException::FactoryException(const std::string &type) : _message()
{
}

const char *FactoryException::what() const noexcept
{
    return _message.c_str();
}
