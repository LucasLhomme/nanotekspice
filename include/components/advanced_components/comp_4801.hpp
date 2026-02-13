//
// Created by crabe on 13/02/2026.
//

#ifndef NANO_1_COMP_4801_HPP
#define NANO_1_COMP_4801_HPP
#include <map>
#include <utility>
#include <vector>
#include "components/Igates.hpp"

namespace nts {
        class Comp_4801 : public AComponent {
        private:
            nts::Tristate getVal(std::size_t pin);
            int getAddress();
            std::vector<std::array<nts::Tristate, 8>> _memory;
        public:
            Comp_4801();
            ~Comp_4801() override = default;
            nts::Tristate compute(std::size_t pin) override;
            void simulate(std::size_t tick) override;
        };
    }

#endif //NANO_1_COMP_4801_HPP