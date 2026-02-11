/*
** EPITECH PROJECT, 2026
** nano
** File description:
** Input
*/
#include "Input.hpp"

Input::Input(std::string name) : AComponent(name)
{
    _value = nts::Undefined;
}

void Input::setValue(nts::Tristate value)
{
    _nextValue = value;
}

void Input::simulate(std::size_t tick)
{
    _value = _nextValue;
}

nts::Tristate Input::compute(std::size_t pin)
{
    return _value;
}
