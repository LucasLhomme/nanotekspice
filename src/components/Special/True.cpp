/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** True
*/

#include "components/Special/True.hpp"
#include "components/Special/Special.hpp"

namespace nts {
    nts::Tristate True::compute(std::size_t pin) {
        if (pin != 1)
            return nts::Undefined;
        return nts::True;
    }

    void True::setValue(nts::Tristate value) {
        (void)value;
    }
}
