/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Output
*/

#include "components/Special/Output.hpp"

namespace nts {
    Output::Output() {}

    nts::Tristate Output::compute(std::size_t pin) {
        if (pin != 1)
            return nts::Undefined;
        return getLinkValue(1);
    }
}