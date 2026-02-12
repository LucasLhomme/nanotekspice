/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Comp_4069
*/

#ifndef NANO_1_COMP4069_HPP
#define NANO_1_COMP4069_HPP

#include "Igates.hpp"
#include <map>

namespace nts {
    class Comp_4069 : public AComponent {
        public:
            Comp_4069() = default;
            ~Comp_4069() override = default;
            nts::Tristate compute(std::size_t pin) override;
    };
}


#endif //NANO_1_COMP4069_HPP