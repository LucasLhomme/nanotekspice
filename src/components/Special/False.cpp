/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** False
*/

#include "components/Special/False.hpp"

namespace nts {

    /**
     * \brief Always return logical False for any queried pin.
     *
     * @param pin Pin number (ignored).
     * @return Tristate::False
     */
    nts::Tristate FalseComponent::compute(std::size_t pin) {
        (void)pin;
        return Tristate::False;
    }

    /**
     * \brief No-op: False component does not accept external value changes.
     *
     * @param value Value to set (ignored).
     */
    void FalseComponent::setValue(nts::Tristate value) {
        (void)value;
    }
}
