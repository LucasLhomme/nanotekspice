/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** AComponent
*/

#include "components/AComponent.hpp"

namespace nts {
    int AComponent::recursionDepth = 0;

    void AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
    {
        _links.insert({pin, std::make_pair(&other, otherPin)});
    }

    void AComponent::simulate(std::size_t tick)
    {
        (void)tick;
    }

    nts::Tristate AComponent::computeSafe(nts::IComponent *other, std::size_t pin)
    {
        if (!other)
            return nts::Undefined;

        if (recursionDepth > 300)
            return nts::Undefined;
        
        recursionDepth++;
        try {
            nts::Tristate res = other->compute(pin);
            recursionDepth--;
            return res;
        } catch (...) {
            recursionDepth--;
            throw;
        }
    }

    nts::Tristate AComponent::getLinkValue(std::size_t pin)
    {
        auto range = _links.equal_range(pin);
        bool hasTrue = false;
        bool hasFalse = false;

        for (auto it = range.first; it != range.second; ++it) {
            nts::Tristate val = computeSafe(it->second.first, it->second.second);
            if (val == nts::True)
                hasTrue = true;
            else if (val == nts::False)
                hasFalse = true;
        }
        if (hasTrue && hasFalse)
            return nts::Undefined;
        if (hasTrue)
            return nts::True;
        if (hasFalse)
            return nts::False;
        return nts::Undefined;
    }

    std::pair<nts::IComponent*, std::size_t> AComponent::getLink(std::size_t pin) const
    {
        auto it = _links.find(pin);

        if (it == _links.end())
            return {nullptr, 0};
        return it->second;
    }
}