/*
** EPITECH PROJECT, 2026
** Nano-1
** File description:
** or
*/

#include "components/elementary_components/or.hpp"

namespace nts {

    Or::Or() {}

    void Or::simulate(std::size_t tick) {
        (void)tick;
    }

    void Or::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
        _links[pin] = std::make_pair(&other, otherPin);
    }

    nts::Tristate Or::compute(std::size_t pin) {
        if (pin == 1 || pin == 2) {
            if (_links.find(pin) == _links.end())
                return nts::Undefined;
            return _links[pin].first->compute(_links[pin].second);
        }
        if (pin == 3) {
            nts::Tristate valueA = nts::Undefined;
            if (_links.find(1) != _links.end())
                valueA = _links[1].first->compute(_links[1].second);
            nts::Tristate valueB = nts::Undefined;
            if (_links.find(2) != _links.end())
                valueB = _links[2].first->compute(_links[2].second);
            if (valueA == nts::True || valueB == nts::True)
                return nts::True;
            if (valueA == nts::Undefined || valueB == nts::Undefined)
                return nts::Undefined;
            return nts::False;
        }
        return nts::Undefined;
    }
}