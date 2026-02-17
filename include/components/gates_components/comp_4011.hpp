//
// Created by crabe on 12/02/2026.
//

#ifndef NANO_1_COMP_4011_HPP
#define NANO_1_COMP_4011_HPP
#include <vector>
#include "../AComponent.hpp"
#include "../Igates.hpp"

namespace nts {
    class Comp_4011 : public Igates {
    private:
        const std::vector<Gate> _gates = {
            {1, 2, 3},
            {5, 6, 4},
            {8, 9, 10},
            {12, 13, 11}
        };
    public:
        Comp_4011() = default;
        ~Comp_4011() override = default;
        nts::Tristate compute(std::size_t pin) override;
    };
} // nts

#endif //NANO_1_COMP_4011_HPP
