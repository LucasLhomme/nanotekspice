//
// Created by crabe on 09/02/2026.
//

#ifndef NANO_1_TRUE_HPP
#define NANO_1_TRUE_HPP
#include <cstddef>
#include "IComponent.hpp"

namespace nts {
    class True : public IComponent {
    public:
        True() = default;
        ~True() override = default;
        void simulate(std::size_t tick);
        Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void setValue(nts::Tristate value);
    };
}

#endif //NANO_1_TRUE_HPP