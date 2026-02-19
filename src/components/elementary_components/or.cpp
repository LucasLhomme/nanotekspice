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
        return getLinkValue(1) || getLinkValue(2);
    }
}