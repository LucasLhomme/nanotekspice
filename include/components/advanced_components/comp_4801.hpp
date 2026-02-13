//
// Created by crabe on 13/02/2026.
//

#ifndef NANO_1_COMP_4001_HPP
#define NANO_1_COMP_4001_HPP
#include <map>
#include <utility>
#include <vector>
#include "components/Igates.hpp"

namespace nts {
    class Comp_4801 : public Igates {
    private:
        const std::vector<Gate> _gates = {
            {1, 2, 3},
            {5, 6, 4},
            {8, 9, 10},
            {12, 13, 11}
        };
        nts::Tristate getVal(std::size_t p);
    public:
        Comp_4801() = default;
        ~Comp_4801() override = default;

        nts::Tristate compute(std::size_t pin) override;
    };
} // nts

#endif //NANO_1_COMP_4001_HPP