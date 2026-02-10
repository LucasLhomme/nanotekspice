/*
/** EPITECH PROJECT, 2025
/** ParsingException.cpp
/** File description:
/** Don't forget to write a description ^^
*/

#include "../../include/Parsing/ParsingException.hpp"

nts::ParsingException::ParsingException(const std::string message) : _message(message)
{
}

const char *nts::ParsingException::what() const noexcept
{
    return _message.c_str();
}