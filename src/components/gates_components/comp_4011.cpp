/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** comp_4011
*/

#include "components/gates_components/comp_4011.hpp"
#include "../../../include/IComponent.hpp"

namespace nts {
    /**
     * \brief Compute values for the 4011 quad NAND gates.
     *
     * @param pin Pin to compute; returns NAND of inputs when matching an output.
     * @return Computed Tristate or forwarded link value.
     */
    nts::Tristate Comp_4011::compute(std::size_t pin) {
        for (const auto &gate : _gates) {
            if (gate.output == pin)
                return !(getLinkValue(gate.input1) && getLinkValue(gate.input2));
        }
        return getLinkValue(pin);
    }
}