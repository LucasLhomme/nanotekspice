/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** comp_4030
*/

#include "components/gates_components/comp_4030.hpp"
#include "components/elementary_components/xor.hpp"
#include <vector>

namespace nts {
    nts::Tristate Comp_4030::compute(std::size_t pin) {
        nts::Tristate value1 = nts::Undefined;
        nts::Tristate value2 = nts::Undefined;

        for (const auto &gate : _gates) {
            if (gate.output == pin) {
                value1 = nts::Undefined;
                value2 = nts::Undefined;
                if (_links.find(gate.input1) != _links.end())
                    value1 = computeSafe(_links[gate.input1].first, _links[gate.input1].second);
                if (_links.find(gate.input2) != _links.end())
                    value2 = computeSafe(_links[gate.input2].first, _links[gate.input2].second);
                return value1 ^ value2;
            }
        }
        if (_links.find(pin) != _links.end())
            return computeSafe(_links[pin].first, _links[pin].second);
        return nts::Undefined;
    }
}
