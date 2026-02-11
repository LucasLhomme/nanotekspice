/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** AComponent
*/

#include "AComponent.hpp"

namespace nts {
    void AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
    {
        _links[pin] = std::make_pair(&other, otherPin);
    }

    void AComponent::simulate(std::size_t tick)
    {
        (void)tick;
    }
}