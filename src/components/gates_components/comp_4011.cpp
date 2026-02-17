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
        nts::Tristate val1 = nts::Undefined;
        nts::Tristate val2 = nts::Undefined;

        for (const auto &gate : _gates) {
            if (gate.output == pin) {
                if (_links.find(gate.input1) != _links.end())
                    val1 = computeSafe(_links[gate.input1].first, _links[gate.input1].second);
                if (_links.find(gate.input2) != _links.end())
                    val2 = computeSafe(_links[gate.input2].first, _links[gate.input2].second);
            return !(val1 && val2);
            }
        }
        if (_links.find(pin) != _links.end())
            return computeSafe(_links[pin].first, _links[pin].second);
        return nts::Undefined;
    }
}
