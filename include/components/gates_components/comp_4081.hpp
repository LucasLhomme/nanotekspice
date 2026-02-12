//
// Created by crabe on 12/02/2026.
//

#ifndef NANO_1_COMP_4081_HPP
#define NANO_1_COMP_4081_HPP
#include <vector>
#include "../AComponent.hpp"
#include "Igates.hpp"

namespace nts {
    class Comp_4081 : public Igates {
    private:
        nts::Tristate computeAnd(nts::Tristate val1, nts::Tristate val2);
        const std::vector<Gate> _gates = {
            {1, 2, 3},
            {5, 6, 4},
            {8, 9, 10},
            {12, 13, 11}
        };
    public:
        Comp_4081() = default;
        ~Comp_4081() override = default;
        nts::Tristate compute(std::size_t pin) override;
    };
} // nts

#endif //NANO_1_COMP_4081_HPP