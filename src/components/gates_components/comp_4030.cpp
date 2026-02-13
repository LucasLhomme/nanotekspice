//
// Created by crabe on 10/02/2026.
//

#include "components/gates_components/comp_4030.hpp"
#include "components/elementary_components/xor.hpp"
#include <vector>

namespace nts {
    nts::Tristate Comp_4030::computeXor(nts::Tristate a, nts::Tristate b)
    {
        if (a == nts::Undefined || b == nts::Undefined)
            return nts::Undefined;
        if (a == b)
            return nts::False;
        return nts::True;
    }

    nts::Tristate Comp_4030::compute(std::size_t pin)
    {
        nts::Tristate val1 = nts::Undefined;
        nts::Tristate val2 = nts::Undefined;

        for (const auto &gate : _gates) {
            if (gate.output == pin) {
                val1 = computeSafe(_links[gate.input1].first, _links[gate.input1].second);
                val2 = computeSafe(_links[gate.input2].first, _links[gate.input2].second);

                return computeXor(val1, val2);
            }
        }
        if (_links.contains(pin))
            return computeSafe(_links[pin].first, _links[pin].second);
        return nts::Undefined;
    }
}