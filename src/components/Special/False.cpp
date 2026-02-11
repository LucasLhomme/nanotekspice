/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** False
*/

#include "components/Special/False.hpp"
#include "components/Special/Special.hpp"

namespace nts {

    nts::Tristate False::compute(std::size_t pin) {
        if (pin != 1)
            return nts::Undefined;
        return nts::False;
    }

    void False::setValue(nts::Tristate value) {
        (void)value;
    }
}
