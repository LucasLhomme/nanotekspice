/*
** EPITECH PROJECT, 2026
** nano
** File description:
** Input
*/
#include "Input.hpp"

Input::Input(std::string name)
{
}

void Input::setValue(nts::Tristate value)
{
    _value = value;
}

nts::Tristate Input::compute(std::size_t pin)
{
    return _value;
}

void Input::simulate(std::size_t tick)
{
}
