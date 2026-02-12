/*
** EPITECH PROJECT, 2026
** nano
** File description:
** AComponent
*/

#include "AComponent.hpp"

void nts::AComponent::simulate(std::size_t tick)
{
}

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    _links[pin].push_back(std::make_pair(&other, otherPin));
}

nts::Tristate nts::AComponent::getLink(std::size_t pin)
{
    if (_links.find(pin) == _links.end() || _links[pin].empty()) {
        return nts::Undefined;
    }
    auto &connections = _links[pin].front();

    return connections.first->compute(connections.second);
}
