/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** AComponent
*/

#include "components/AComponent.hpp"
#include "components/Special/Input.hpp"
#include "components/Special/Output.hpp"
#include "components/Special/Clock.hpp"
#include "components/Special/True.hpp"
#include "components/Special/False.hpp"

namespace nts {
    int AComponent::recursionDepth = 0;

    static bool isSourceComponent(nts::IComponent *comp)
    {
        if (dynamic_cast<nts::Input*>(comp))
            return true;
        if (dynamic_cast<nts::Clock*>(comp))
            return true;
        if (dynamic_cast<nts::TrueComponent*>(comp))
            return true;
        if (dynamic_cast<nts::FalseComponent*>(comp))
            return true;
        return false;
    }

    void AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
    {
        if (_links.find(pin) != _links.end()) {
            bool existingIsSource = isSourceComponent(_links[pin].first);
            bool newIsOutput = dynamic_cast<nts::Output*>(&other) != nullptr;
            if (existingIsSource && newIsOutput)
                return;
        }
        _links[pin] = std::make_pair(&other, otherPin);
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
}
