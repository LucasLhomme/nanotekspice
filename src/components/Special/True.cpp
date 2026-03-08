/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** True
*/

#include "components/Special/True.hpp"

namespace nts {
    /**
     * \brief Always return logical True for any queried pin.
     *
     * @param pin Pin number (ignored).
     * @return Tristate::True
     */
    nts::Tristate TrueComponent::compute(std::size_t pin) {
        (void)pin;
        return Tristate::True;
    }

    /**
     * \brief No-op: True component does not accept external value changes.
     *
     * @param value Value to set (ignored).
     */
    void TrueComponent::setValue(nts::Tristate value) {
        (void)value;
    }
}
