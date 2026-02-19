/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** comp_4030
*/

#include "components/gates_components/comp_4030.hpp"
#include "components/elementary_components/xor.hpp"

namespace nts {
    nts::Tristate Comp_4030::compute(std::size_t pin) {
        for (const auto &gate : _gates) {
            if (gate.output == pin)
                return getLinkValue(gate.input1) ^ getLinkValue(gate.input2);
        }
        return getLinkValue(pin);
    }
}