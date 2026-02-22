/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** xor
*/

#include "components/elementary_components/xor.hpp"

namespace nts {

    Xor::Xor() {}

    nts::Tristate Xor::compute(std::size_t pin)
    {
        if (pin != 3)
            return nts::Undefined;
        return getLinkValue(1) ^ getLinkValue(2);
    }
}