//
// Created by crabe on 13/02/2026.
//

#include "../../../include/components/advanced_components/comp_4008.hpp"

#include <array>

#include "../../../include/IComponent.hpp"

namespace nts {
    nts::Tristate Comp_4008::compute(std::size_t pin)
    {
        nts::Tristate carryIn = getVal(9);
        const size_t carryOut = 14;
        static const std::vector<size_t> sumPins = {10, 11, 12, 13};
        static const std::vector<std::pair<size_t, size_t>> inputs = {{
            {7, 6},
            {5, 4},
            {3, 2},
            {1, 15}
        }};

        for (int i = 0; i < 4; ++i) {
            nts::Tristate a = getVal(inputs[i].first);
            nts::Tristate b = getVal(inputs[i].second);
            nts::Tristate sum = (a ^ b) ^ carryIn;
            nts::Tristate term1 = a && b;
            nts::Tristate term2 = carryIn && (a ^ b);
            nts::Tristate nextCarry = term1 || term2;
            if (pin == sumPins[i])
                return sum;
            carryIn = nextCarry;
        }
        if (pin == carryOut)
            return carryIn;
        return Tristate::Undefined;
    }
} // nts