/*
** EPITECH PROJECT, 2026
** nano
** File description:
** Clock
*/
#include "Clock.hpp"

Clock::Clock(std::string name)
{
}

void Clock::setValue(nts::Tristate value)
{
    _value = value;
}

nts::Tristate Clock::compute(std::size_t pin)
{
    return _value;
}

void Clock::simulate(std::size_t tick)
{
    if (_value == nts::True)
        _value = nts::False;
    else if (_value == nts::False)
        _value = nts::True;
    else _value = nts::Undefined;
}