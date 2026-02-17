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
        if (pin != 2 || _links.find(1) == _links.end())
            return nts::Undefined;
        nts::Tristate value = computeSafe(_links[1].first, _links[1].second);
        return !value;
    }
}