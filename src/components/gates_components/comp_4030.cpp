/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** comp_4030
*/

#include "components/gates_components/comp_4030.hpp"
#include "components/elementary_components/xor.hpp"

namespace nts {
    /**
     * \brief Compute values for the 4030 XOR gates collection.
     *
     * @param pin Pin number to compute; when matching a gate output returns XOR of inputs.
     * @return Computed Tristate or forwarded link value.
     */
    nts::Tristate Comp_4030::compute(std::size_t pin) {
        for (const auto &gate : _gates) {
            if (gate.output == pin)
                return getLinkValue(gate.input1) ^ getLinkValue(gate.input2);
        }
        return getLinkValue(pin);
    }
}