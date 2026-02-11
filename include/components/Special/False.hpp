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
#include "AComponent.hpp"

namespace nts {
    class False : public AComponent {
    public:
        False() = default;
        ~False() override = default;
        Tristate compute(std::size_t pin) override;
        void setValue(nts::Tristate value);
    };
}

#endif //NANO_1_FALSE_HPP
