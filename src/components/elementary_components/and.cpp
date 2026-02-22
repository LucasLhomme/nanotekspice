/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** and
*/

#include "components/elementary_components/and.hpp"

namespace nts {

    And::And() {}

    nts::Tristate And::compute(std::size_t pin)
    {
        if (pin != 3)
            return nts::Undefined;
        return getLinkValue(1) && getLinkValue(2);
    }
}