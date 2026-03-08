/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** not
*/

#include "components/elementary_components/not.hpp"

namespace nts {

    /**
     * \brief Compute logical NOT of input on pin 1, result on pin 2.
     *
     * @param pin Pin number to compute (expects 2).
     * @return Logical NOT of pin 1, or Undefined for invalid pin.
     */
    nts::Tristate Not::compute(std::size_t pin)
    {
        if (pin != 2)
            return nts::Undefined;
        return !getLinkValue(1);
    }
}