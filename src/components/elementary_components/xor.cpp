/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** xor
*/

#include "../../../include/components/elementary_components/xor.hpp"
#include "../../../include/Exception.hpp"

namespace nts {

    Xor::Xor() {}

    nts::Tristate Xor::compute(std::size_t pin)
    {
        if (pin != 3)
            return nts::Undefined;
        nts::Tristate a = (_links.count(1)) ? computeSafe(_links[1].first, _links[1].second) : nts::Undefined;
        nts::Tristate b = (_links.count(2)) ? computeSafe(_links[2].first, _links[2].second) : nts::Undefined;
        return a ^ b;
    }
}

