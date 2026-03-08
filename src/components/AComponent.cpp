/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** AComponent
*/

#include "components/AComponent.hpp"
#include "components/Special/Input.hpp"
#include "components/Special/Clock.hpp"
#include "components/Special/True.hpp"
#include "components/Special/False.hpp"
#include "components/Special/Output.hpp"

namespace nts {
    int AComponent::recursionDepth = 0;

    /**
     * \brief Check whether a component is a source-type (Input/Clock/True/False).
     *
     * @param comp Pointer to the component to inspect.
     * @return true if component is a source, false otherwise.
     */
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

    /**
     * \brief Link this component's pin to another component's pin.
     *
     * @param pin Local pin number.
     * @param other Reference to the other component to link.
     * @param otherPin Other component's pin number.
     */
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

    /**
     * \brief Default simulate implementation for base components.
     *
     * @param tick Current simulation tick (unused in base class).
     */
    void AComponent::simulate(std::size_t tick)
    {
        (void)tick;
    }

    /**
     * \brief Safely compute the value of a linked component, protecting recursion.
     *
     * @param other Pointer to the other component to compute.
     * @param pin Pin number on the other component.
     * @return Computed Tristate value or Undefined on error/overflow.
     */
    nts::Tristate AComponent::computeSafe(nts::IComponent *other, std::size_t pin)
    {
        if (!other)
            return nts::Undefined;

        if (recursionDepth > 300)
            return nts::Undefined;
        struct RecursionGuard {
            int &depth;
            explicit RecursionGuard(int &d) : depth(d) { depth++; }
            ~RecursionGuard() { depth--; }
        };

        RecursionGuard guard(recursionDepth);
        nts::Tristate res = other->compute(pin);
        return res;
    }


    /**
     * \brief Retrieve the tristate value from a linked pin.
     *
     * @param pin Local pin number to query.
     * @return Tristate value from the connected component or Undefined.
     */
    nts::Tristate AComponent::getLinkValue(std::size_t pin)
    {
        auto it = _links.find(pin);
        
        if (it == _links.end())
            return nts::Undefined;
        return computeSafe(it->second.first, it->second.second);
    }

    /**
     * \brief Get the connected component and pin for a given local pin.
     *
     * @param pin Local pin number.
     * @return Pair of pointer to the connected component and its pin.
     */
    std::pair<nts::IComponent*, std::size_t> AComponent::getLink(std::size_t pin) const
    {
        auto it = _links.find(pin);

        if (it == _links.end())
            return {nullptr, 0};
        return it->second;
    }
}