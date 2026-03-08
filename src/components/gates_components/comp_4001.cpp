#include "components/gates_components/comp_4001.hpp"

namespace nts {
    /**
     * \brief Compute values for the 4001 quad NOR gates.
     *
     * @param pin Pin number to compute; when it matches a gate output, returns NOR of inputs.
     * @return Computed Tristate or forwarded link value.
     */
    nts::Tristate Comp_4001::compute(std::size_t pin)
    {
        for (const auto &gate : _gates) {
            if (gate.output == pin)
                return !(getLinkValue(gate.input1) || getLinkValue(gate.input2));
        }
        return getLinkValue(pin);
    }
}