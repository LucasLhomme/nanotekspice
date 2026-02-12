/*
** EPITECH PROJECT, 2026
** nano
** File description:
** Clock
*/
#include "../../include/Special-Components/Clock.hpp"

nts::Clock::Clock()
{
    _value = nts::Undefined;
}

void nts::Clock::setValue(nts::Tristate value)
{
    _nextValue = value;
}

void nts::Clock::simulate(std::size_t tick)
{
    _value = _nextValue;

    if (_value == nts::True)
        _nextValue = nts::False;
    else if (_value == nts::False)
        _nextValue = nts::True;
}

nts::Tristate nts::Clock::compute(std::size_t pin)
{
    return _value = _nextValue;
}
