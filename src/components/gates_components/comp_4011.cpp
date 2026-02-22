/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** comp_4011
*/

#include "components/gates_components/comp_4011.hpp"
#include "../../../include/IComponent.hpp"

namespace nts {
    nts::Tristate Comp_4011::compute(std::size_t pin) {
        for (const auto &gate : _gates) {
            if (gate.output == pin)
                return !(getLinkValue(gate.input1) && getLinkValue(gate.input2));
        }
        return getLinkValue(pin);
    }
}