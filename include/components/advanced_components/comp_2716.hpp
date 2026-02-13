//
// Created by crabe on 13/02/2026.
//

#ifndef NANO_1_COMP_2716_HPP
#define NANO_1_COMP_2716_HPP
#include <map>
#include <utility>
#include <vector>
#include "components/advanced_components/AdvancedComponent.hpp"

namespace nts {
        class Comp_2716 : public AdvancedComponent {
        private:
            int getAddress();
            std::vector<std::array<nts::Tristate, 8>> _memory;
        public:
            Comp_2716();
            ~Comp_2716() override = default;
            nts::Tristate compute(std::size_t pin) override;
            void simulate(std::size_t tick) override;
        };
    }

#endif //NANO_1_COMP_2716_HPP