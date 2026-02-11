/*
** EPITECH PROJECT, 2026
** nano
** File description:
** Clock
*/
#include "ClockComponent.hpp"

nts::ClockComponent::ClockComponent(std::string name)
{
    _value = nts::Undefined;
}

void nts::ClockComponent::setValue(nts::Tristate value)
{
    _nextValue = value;
}

void nts::ClockComponent::simulate(std::size_t tick)
{
    _value = _nextValue;

    if (_value == nts::True)
        _nextValue = nts::False;
    else if (_value == nts::False)
        _nextValue = nts::True;
}

nts::Tristate nts::ClockComponent::compute(std::size_t pin)
{
    return _value = _nextValue;
}
