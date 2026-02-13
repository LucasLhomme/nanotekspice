//
// Created by crabe on 13/02/2026.
//

#ifndef NANO_1_COMP_4017_HPP
#define NANO_1_COMP_4017_HPP
#include <map>
#include <utility>
#include <vector>
#include "components/Igates.hpp"

namespace nts {
    class Comp_4017 : public AComponent {
    private:
        nts::Tristate getVal(std::size_t pin);
        int _count;
        nts::Tristate _prevClock;
    public:
        Comp_4017();
        ~Comp_4017() override = default;

        nts::Tristate compute(std::size_t pin) override;
        void simulate(std::size_t tick) override;
    };
}

#endif //NANO_1_COMP_4017_HPP