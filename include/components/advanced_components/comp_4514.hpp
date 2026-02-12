//
// Created by crabe on 12/02/2026.
//

#ifndef NANO_1_COMP_4514_HPP
#define NANO_1_COMP_4514_HPP

#include <map>
#include <utility>
#include <vector>
#include "components/Igates.hpp"

namespace nts {
    class Comp_4514 : public Igates {
    private:
        const std::vector<Gate> _gates = {
            {1, 2, 3},
            {5, 6, 4},
            {8, 9, 10},
            {12, 13, 11}
        };
        nts::Tristate getVal(std::size_t p);
    public:
        Comp_4514() = default;
        ~Comp_4514() override = default;

        nts::Tristate compute(std::size_t pin) override;
    };
} // nts

#endif //NANO_1_COMP_4514_HPP
