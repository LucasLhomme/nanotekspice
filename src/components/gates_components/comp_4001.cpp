#include "components/gates_components/comp_4001.hpp"

namespace nts {
    nts::Tristate Comp_4001::compute(std::size_t pin)
    {
        for (const auto &gate : _gates) {
            if (gate.output == pin)
                return !(getLinkValue(gate.input1) || getLinkValue(gate.input2));
        }
        return getLinkValue(pin);
    }
}