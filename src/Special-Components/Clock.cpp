/*
** EPITECH PROJECT, 2026
** nano
** File description:
** Clock
*/
#include "Clock.hpp"

Clock::Clock(std::string name) : AComponent(name)
{
    _value = nts::Undefined;
}

void Clock::setValue(nts::Tristate value)
{
    _nextValue = value;
}

void Clock::simulate(std::size_t tick)
{
    _value = _nextValue;

    if (_value == nts::True)
        _nextValue = nts::False;
    else if (_value == nts::False)
        _nextValue = nts::True;
}

nts::Tristate Clock::compute(std::size_t pin)
{
    return _value = _nextValue;
}
