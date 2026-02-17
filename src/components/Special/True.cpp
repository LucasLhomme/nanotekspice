/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** True
*/

#include "components/Special/True.hpp"

namespace nts {
    nts::Tristate TrueComponent::compute(std::size_t pin) {
        if (!pin)
            return nts::Undefined;
        return nts::True;
    }

    void TrueComponent::setValue(nts::Tristate value) {
        (void)value;
    }
}
