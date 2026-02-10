//
// Created by crabe on 10/02/2026.
//

#ifndef NANO_1_IGATES_HPP
#define NANO_1_IGATES_HPP
#include "../../IComponent.hpp"

namespace nts {
    class Igates : public IComponent {
    public:
        ~Igates() override = default;
        void simulate(std::size_t tick) override = 0;
        nts::Tristate compute(std::size_t pin) override = 0;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override = 0;
    };
}

#endif //NANO_1_IGATES_HPP