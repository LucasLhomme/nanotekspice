/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** comp_4071 Header
*/

#ifndef NANO_1_COMP4071_HPP
#define NANO_1_COMP4071_HPP

#include "../AComponent.hpp"
#include <map>

namespace nts {
    class Comp_4071 : public AComponent {
        public:
            Comp_4071() = default;
            ~Comp_4071() override = default;
            nts::Tristate compute(std::size_t pin) override;
    };
}

#endif //NANO_1_COMP4071_HPP