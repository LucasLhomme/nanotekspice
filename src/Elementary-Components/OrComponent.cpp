/*
** EPITECH PROJECT, 2026
** nano
** File description:
** OrComponent
*/

#include "../../include/Elementary-Components/OrComponent.hpp"

OrComponent::OrComponent()
{
}

nts::Tristate OrComponent::compute(std::size_t pin)
{
    if (pin == 3) {
        return getLink(1) || getLink(2); 
    }
    return getLink(pin);
}
