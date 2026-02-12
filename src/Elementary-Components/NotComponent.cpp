/*
** EPITECH PROJECT, 2026
** nano
** File description:
** NotComponent
*/

#include "../../include/Elementary-Components/NotComponent.hpp"

NotComponent::NotComponent()
{
}

nts::Tristate NotComponent::compute(std::size_t pin)
{
    if (pin == 2) {
        return getLink(1) == nts::Tristate::True ? nts::Tristate::False : (getLink(1) == nts::Tristate::False ? nts::Tristate::True : nts::Tristate::Undefined);
    }
    return getLink(pin);
}
