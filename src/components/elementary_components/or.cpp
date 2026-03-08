/*
** EPITECH PROJECT, 2026
** Nano-1
** File description:
** or
*/

#include "components/elementary_components/or.hpp"

namespace nts {

    /**
     * \brief Default constructor for OR gate.
     */
    Or::Or() {}

    /**
     * \brief Compute OR of two inputs, available on pin 3.
     *
     * @param pin Pin number to compute (expects 3).
     * @return Logical OR of pin 1 and pin 2, or Undefined for invalid pin.
     */
    nts::Tristate Or::compute(std::size_t pin) {
        if (pin != 3)
            return nts::Undefined;
        return getLinkValue(1) || getLinkValue(2);
    }
}