//
// Created by crabe on 12/02/2026.
//

#include "components/gates_components/comp_4081.hpp"
#include "../../../include/components/elementary_components/and.hpp"
#include "../../../include/IComponent.hpp"

namespace nts {

    nts::Tristate Comp_4081::computeAnd(nts::Tristate val1, nts::Tristate val2)
    {
        if (val1 == nts::False || val2 == nts::False)
            return nts::False;
        if (val1 == nts::True && val2 == nts::True)
            return nts::True;
        return nts::Undefined;
    }
    nts::Tristate Comp_4081::compute(std::size_t pin) {
        nts::Tristate val1 = nts::Undefined;
        nts::Tristate val2 = nts::Undefined;

        for (const auto &gate : _gates) {
            if (gate.output == pin) {
                if (_links.find(gate.input1) != _links.end())
                    val1 = computeSafe(_links[gate.input1].first, _links[gate.input1].second);
                if (_links.find(gate.input2) != _links.end())
                    val2 = computeSafe(_links[gate.input2].first, _links[gate.input2].second);
            return computeAnd(val1, val2);
            }
        }
        if (_links.contains(pin))
            return computeSafe(_links[pin].first, _links[pin].second);
        return nts::Undefined;
    }

} // nts