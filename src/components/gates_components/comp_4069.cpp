/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Gate4069
*/

#include "components/gates_components/comp_4069.hpp"

namespace nts {
    /**
     * \brief Compute values for 4069 inverters collection.
     *
     * @param pin Pin number to compute; when matching a gate output returns NOT of input1.
     * @return Computed Tristate or forwarded link value.
     */
    nts::Tristate Comp_4069::compute(std::size_t pin)
    {
        for (const auto &gate : _gates) {
            if (gate.output == pin)
                return !getLinkValue(gate.input1);
        }
        return getLinkValue(pin);
    }
}