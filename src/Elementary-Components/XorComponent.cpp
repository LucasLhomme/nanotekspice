/*
** EPITECH PROJECT, 2026
** nano
** File description:
** XorComponent
*/

#include "../../include/Elementary-Components/XorComponent.hpp"

XorComponent::XorComponent()
{
}

nts::Tristate XorComponent::compute(std::size_t pin)
{
    if (pin == 3) {
        return getLink(1) ^ getLink(2);
    }
    return getLink(pin);
}
