//
// Created by crabe on 12/02/2026.
//

#ifndef NANO_1_COMP_4512_HPP
#define NANO_1_COMP_4512_HPP

#include <map>
#include <utility>
#include <vector>
#include "components/advanced_components/AdvancedComponent.hpp"
#include "components/Igates.hpp"

namespace nts {
    class Comp_4512 : public AdvancedComponent {
    private:
        const std::vector<Igates::Gate> _gates = {
            {1, 2, 3},
            {5, 6, 4},
            {8, 9, 10},
            {12, 13, 11}
        };
    public:
        Comp_4512() = default;
        ~Comp_4512() override = default;

        nts::Tristate compute(std::size_t pin) override;
    };
} // nts

#endif //NANO_1_COMP_4512_HPP