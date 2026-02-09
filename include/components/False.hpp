//
// Created by crabe on 09/02/2026.
//

#ifndef NANO_1_TRUE_HPP
#define NANO_1_TRUE_HPP
#include <cstddef>
#include "IComponent.hpp"

namespace nts {
    class False : public IComponent {
    public:
        False() = default;
        ~False() override = default;
        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;

        ComponentType getType();

        void setValue(nts::Tristate value);
    };
}

#endif //NANO_1_TRUE_HPP
