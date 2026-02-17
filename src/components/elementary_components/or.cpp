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
        if (pin != 3)
            return nts::Undefined;
        nts::Tristate valueA = nts::Undefined;
        nts::Tristate valueB = nts::Undefined;
        if (_links.find(1) != _links.end())
            valueA = computeSafe(_links[1].first, _links[1].second);
        if (_links.find(2) != _links.end())
            valueB = computeSafe(_links[2].first, _links[2].second);
        return valueA || valueB;
    }
}