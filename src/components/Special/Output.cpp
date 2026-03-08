/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Output
*/

#include "components/Special/Output.hpp"

namespace nts {
    /**
     * \brief Default constructor for Output.
     */
    Output::Output() {}

    /**
     * \brief Compute the value presented on the output pin (pin 1).
     *
     * @param pin Pin number to read (only 1 is valid).
     * @return Tristate value from the connected link or Undefined.
     */
    nts::Tristate Output::compute(std::size_t pin) {
        if (pin != 1)
            return nts::Undefined;
        return getLinkValue(1);
    }
}