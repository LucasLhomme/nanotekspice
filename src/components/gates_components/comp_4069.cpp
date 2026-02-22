/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Gate4069
*/

#include "components/gates_components/comp_4069.hpp"

namespace nts {
    nts::Tristate Comp_4069::compute(std::size_t pin)
    {
        for (const auto &gate : _gates) {
            if (gate.output == pin)
                return !getLinkValue(gate.input1);
        }
        return getLinkValue(pin);
    }
}