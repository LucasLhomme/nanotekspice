/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** xor
*/

#include "components/elementary_components/xor.hpp"

namespace nts {

    /**
     * \brief Default constructor for XOR gate.
     */
    Xor::Xor() {}

    /**
     * \brief Compute XOR of two inputs, available on pin 3.
     *
     * @param pin Pin number to compute (expects 3).
     * @return Logical XOR of pin 1 and pin 2, or Undefined for invalid pin.
     */
    nts::Tristate Xor::compute(std::size_t pin)
    {
        if (pin != 3)
            return nts::Undefined;
        return getLinkValue(1) ^ getLinkValue(2);
    }
}