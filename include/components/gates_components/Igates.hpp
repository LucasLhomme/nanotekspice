//
// Created by crabe on 10/02/2026.
//

#ifndef NANO_1_IGATES_HPP
#define NANO_1_IGATES_HPP
#include "components/AComponent.hpp"

namespace nts {
    class Igates : public AComponent {
    public:
        struct Gate {
            std::size_t input1;
            std::size_t input2;
            std::size_t output;
        };
        ~Igates() override = default;
        nts::Tristate compute(std::size_t pin) override = 0;
    };
}

#endif //NANO_1_IGATES_HPP