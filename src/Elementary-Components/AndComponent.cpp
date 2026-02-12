/*
** EPITECH PROJECT, 2026
** nano
** File description:
** AndComponent
*/
#include "AndComponent.hpp"

nts::AndComponent::AndComponent()
{
}

nts::Tristate nts::AndComponent::compute(std::size_t pin)
{
    if (pin == 3) {
        return getLink(1) && getLink(2); 
    }
    return getLink(pin);
}
