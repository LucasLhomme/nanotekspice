/*
** EPITECH PROJECT, 2026
** nano
** File description:
** InputComponent
*/
#include "../../include/Special-Components/InputComponent.hpp"

nts::InputComponent::InputComponent()
{
    _value = nts::Undefined;
}

void nts::InputComponent::setValue(nts::Tristate value)
{
    _nextValue = value;
}

void nts::InputComponent::simulate(std::size_t tick)
{
    _value = _nextValue;
}

nts::Tristate nts::InputComponent::compute(std::size_t pin)
{
    return _value;
}
