/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** comp_4081
*/

#include "components/gates_components/comp_4081.hpp"
#include "../../../include/components/elementary_components/and.hpp"
#include "../../../include/IComponent.hpp"

namespace nts {
    nts::Tristate Comp_4081::compute(std::size_t pin) {

        for (const auto &gate : _gates) {
            if (gate.output == pin) {
                nts::Tristate value1 = nts::Undefined;
                nts::Tristate value2 = nts::Undefined;

                if (_links.find(gate.input1) != _links.end())
                    value1 = computeSafe(_links[gate.input1].first, _links[gate.input1].second);
                if (_links.find(gate.input2) != _links.end())
                    value2 = computeSafe(_links[gate.input2].first, _links[gate.input2].second);
                return value1 && value2;
            }
        }
        return nts::Undefined;
    }
}
