/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** comp_4081
*/

#include "components/gates_components/comp_4081.hpp"
#include "../../../include/IComponent.hpp"

namespace nts {
    /**
     * \brief Compute values for 4081 AND gates collection.
     *
     * @param pin Pin number to compute; when matching an output returns AND of inputs.
     * @return Computed Tristate or forwarded link value.
     */
    nts::Tristate Comp_4081::compute(std::size_t pin) {
        for (const auto &gate : _gates) {
            if (gate.output == pin)
                return getLinkValue(gate.input1) && getLinkValue(gate.input2);
        }
        return getLinkValue(pin);
    }
}