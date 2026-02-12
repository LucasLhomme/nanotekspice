//
// Created by crabe on 12/02/2026.
//

#include "components/gates_components/comp_4011.hpp"
#include "../../../include/IComponent.hpp"

namespace nts {

    nts::Tristate Comp_4011::computeNand(nts::Tristate val1, nts::Tristate val2)
    {
        if (val1 == nts::False && val2 == nts::False)
            return nts::True;
        if (val1 == nts::True && val2 == nts::True)
            return nts::False;
        if (val1 == nts::Undefined || val2 == nts::Undefined)
            return nts::Undefined;
        return nts::True;
    }
    nts::Tristate Comp_4011::compute(std::size_t pin) {
        nts::Tristate val1 = nts::Undefined;
        nts::Tristate val2 = nts::Undefined;

        for (const auto &gate : _gates) {
            if (gate.output == pin) {
                if (_links.find(gate.input1) != _links.end())
                    val1 = _links[gate.input1].first->compute(_links[gate.input1].second);
                if (_links.find(gate.input2) != _links.end())
                    val2 = _links[gate.input2].first->compute(_links[gate.input2].second);
            return computeNand(val1, val2);
            }
        }
        if (_links.contains(pin))
            return _links[pin].first->compute(_links[pin].second);
        return nts::Undefined;
    }

} // nts