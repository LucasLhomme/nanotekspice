//
// Created by crabe on 13/02/2026.
//

#include "../../../include/components/advanced_components/comp_4008.hpp"

#include <array>

#include "../../../include/IComponent.hpp"

namespace nts {
    //TODO: TROUVER UN MOYEN DE NE PAS DUPLIQUER LE CODE
    
    // XOR qui gère le Tristate
    static nts::Tristate local_xor(nts::Tristate a, nts::Tristate b) {
        if (a == nts::Undefined || b == nts::Undefined) return nts::Undefined;
        return (a == b) ? nts::False : nts::True;
    }

    // AND qui gère le Tristate (0 est absorbant)
    static nts::Tristate local_and(nts::Tristate a, nts::Tristate b) {
        if (a == nts::False || b == nts::False) return nts::False;
        if (a == nts::Undefined || b == nts::Undefined) return nts::Undefined;
        return nts::True;
    }

    // OR qui gère le Tristate (1 est absorbant)
    static nts::Tristate local_or(nts::Tristate a, nts::Tristate b) {
        if (a == nts::True || b == nts::True) return nts::True;
        if (a == nts::Undefined || b == nts::Undefined) return nts::Undefined;
        return nts::False;
    }

    nts::Tristate Comp_4008::compute(std::size_t pin)
    {
        nts::Tristate carryIn = getVal(9);
        const size_t carryOut = 14;
        static const std::vector<std::pair<size_t, size_t>> inputs = {{
            {7, 6},   // Bit 1 (A1, B1)
            {5, 4},   // Bit 2 (A2, B2)
            {3, 2},   // Bit 3 (A3, B3)
            {1, 15}   // Bit 4 (A4, B4)
        }};
        static const std::vector<size_t> sumPins = {10, 11, 12, 13};

        for (int i = 0; i < 4; ++i) {
            nts::Tristate a = getVal(inputs[i].first);
            nts::Tristate b = getVal(inputs[i].second);

            nts::Tristate sum = local_xor(local_xor(a, b), carryIn);

            nts::Tristate term1 = local_and(a, b);
            nts::Tristate term2 = local_and(carryIn, local_xor(a, b));
            nts::Tristate nextCarry = local_or(term1, term2);

            // if is the pin we want, we give the sum
            if (pin == sumPins[i]) {
                return sum;
            }
            carryIn = nextCarry;
        }
        if (pin == carryOut) {
            return carryIn;
        }

        return Tristate::Undefined;
    }
} // nts