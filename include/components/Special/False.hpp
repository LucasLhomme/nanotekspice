/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** False
*/

#ifndef NANO_1_FALSE_HPP
#define NANO_1_FALSE_HPP

#include <cstddef>
#include "IComponent.hpp"
#include "components/AComponent.hpp"

namespace nts {
    class FalseComponent : public AComponent {
    public:
        FalseComponent() = default;
        ~FalseComponent() override = default;
        Tristate compute(std::size_t pin) override;
        void setValue(nts::Tristate value);
    };
}

#endif //NANO_1_FALSE_HPP
