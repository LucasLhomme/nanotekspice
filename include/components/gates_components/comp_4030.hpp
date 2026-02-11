//
// Created by crabe on 10/02/2026.
//

#ifndef NANO_1_COMP_4030_HPP
#define NANO_1_COMP_4030_HPP
#include <map>
#include <utility>
#include <vector>

#include "Igates.hpp"

namespace nts {
    class Comp_4030 : public Igates {
    private:
        std::map<std::size_t, std::pair<nts::IComponent*, std::size_t>> _links;         nts::Tristate computeXor(nts::Tristate a, nts::Tristate b);
        const std::vector<Gate> _gates = {
            {1, 2, 3},
            {5, 6, 4},
            {8, 9, 10},
            {12, 13, 11}
        };
    public:
        ~Comp_4030() override = default;
        Comp_4030() = default;
        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
    };
} // nts

#endif //NANO_1_COMP_4030_HPP

