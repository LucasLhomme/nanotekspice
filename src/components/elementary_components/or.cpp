/*
** EPITECH PROJECT, 2026
** Nano-1
** File description:
** or
*/

#include "components/elementary_components/or.hpp"

namespace nts {

    Or::Or() {}

    nts::Tristate Or::compute(std::size_t pin) {
        if (pin == 1 || pin == 2) {
            if (_links.find(pin) == _links.end())
                return nts::Undefined;
            return computeSafe(_links[pin].first, _links[pin].second);
        }
        if (pin == 3) {
            nts::Tristate valueA = nts::Undefined;
            if (_links.find(1) != _links.end())
                valueA = computeSafe(_links[1].first, _links[1].second);
            nts::Tristate valueB = nts::Undefined;
            if (_links.find(2) != _links.end())
                valueB = computeSafe(_links[2].first, _links[2].second);
            if (valueA == nts::True || valueB == nts::True)
                return nts::True;
            if (valueA == nts::Undefined || valueB == nts::Undefined)
                return nts::Undefined;
            return nts::False;
        }
        return nts::Undefined;
    }
}