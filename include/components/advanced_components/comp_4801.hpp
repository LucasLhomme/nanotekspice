//
// Created by crabe on 13/02/2026.
//

#ifndef NANO_1_COMP_4801_HPP
#define NANO_1_COMP_4801_HPP
#include <map>
#include <array>
#include <utility>
#include <vector>
#include "components/advanced_components/AdvancedComponent.hpp"

namespace nts {
        class Comp_4801 : public AdvancedComponent {
        private:
            int getAddress();
            std::vector<std::array<nts::Tristate, 8>> _memory;
            std::array<nts::Tristate, 8> _outputBuffer;
        public:
            Comp_4801();
            ~Comp_4801() override = default;
            nts::Tristate compute(std::size_t pin) override;
            void simulate(std::size_t tick) override;
        };
    }

#endif //NANO_1_COMP_4801_HPP