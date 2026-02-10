//
// Created by crabe on 10/02/2026.
//

#ifndef NANO_1_COMP_4030_HPP
#define NANO_1_COMP_4030_HPP
#include "Igates.hpp"

namespace nts {
    class comp_4030 : public Igates {
        public:
            comp_4030() = default;
            ~comp_4030() override = default;
            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
    };
} // nts

#endif //NANO_1_COMP_4030_HPP