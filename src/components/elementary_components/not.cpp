/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** not
*/

#include "components/elementary_components/not.hpp"

namespace nts {

    nts::Tristate Not::compute(std::size_t pin)
    {
        if (pin != 2)
            return nts::Undefined;
        if (_links.find(1) == _links.end())
            return nts::Undefined;
        auto link = _links[1];
        nts::Tristate value = computeSafe(link.first, link.second);
        if (value == nts::True)
            return nts::False;
        if (value == nts::False)
            return nts::True;
        return nts::Undefined;
    }
}