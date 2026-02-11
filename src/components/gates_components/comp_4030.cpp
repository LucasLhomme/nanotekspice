//
// Created by crabe on 10/02/2026.
//

#include "components/gates_components/comp_4030.hpp"
#include "components/elementary_components/xor.hpp"
#include <vector>

namespace nts {

    void Comp_4030::simulate(std::size_t tick)
    {
        (void)tick;
    }

    void Comp_4030::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
    {
        _links[pin] = std::make_pair(&other, otherPin);
    }

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
                val1 = _links[gate.input1].first->compute(_links[gate.input1].second);
                val2 = _links[gate.input2].first->compute(_links[gate.input2].second);

                return computeXor(val1, val2);
            }
        }
        if (_links.contains(pin))
            return _links[pin].first->compute(_links[pin].second);
        return nts::Undefined;
    }
} // nts