/*
** EPITECH PROJECT, 2026
** nano
** File description:
** UnknowTypeException
*/
#include "Exception/UnknowTypeException.hpp"

UnknowTypeException::UnknowTypeException(const std::string &type) : _message("Unknown component type '" + type + "', can't create it.")
{
}

const char *UnknowTypeException::what() const noexcept
{
    return _message.c_str();
}
