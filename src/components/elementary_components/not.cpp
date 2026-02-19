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
        return !getLinkValue(1);
    }
}