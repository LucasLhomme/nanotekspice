/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** False
*/

#include "components/Special/False.hpp"

namespace nts {

    nts::Tristate FalseComponent::compute(std::size_t pin) {
        (void)pin;
        return Tristate::False;
    }

    void FalseComponent::setValue(nts::Tristate value) {
        (void)value;
    }
}
