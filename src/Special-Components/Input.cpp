/*
** EPITECH PROJECT, 2026
** nano
** File description:
** Input
*/

#include "../../include/Special-Components/Input.hpp"

nts::Input::Input()
{
    _value = nts::Undefined;
}

void nts::Input::setValue(nts::Tristate value)
{
    _nextValue = value;
}

void nts::Input::simulate(std::size_t tick)
{
    _value = _nextValue;
}

nts::Tristate nts::Input::compute(std::size_t pin)
{
    return _value;
}
