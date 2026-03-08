/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** and
*/

#include "components/elementary_components/and.hpp"

namespace nts {

    /**
     * \brief Default constructor for AND gate.
     */
    And::And() {}

    /**
     * \brief Compute AND of two inputs, available on pin 3.
     *
     * @param pin Pin number to compute (expects 3).
     * @return Logical AND of pin 1 and pin 2, or Undefined for invalid pin.
     */
    nts::Tristate And::compute(std::size_t pin)
    {
        if (pin != 3)
            return nts::Undefined;
        return getLinkValue(1) && getLinkValue(2);
    }
}