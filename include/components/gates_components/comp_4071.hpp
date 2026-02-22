/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** comp_4071 Header
*/

#ifndef NANO_1_COMP4071_HPP
#define NANO_1_COMP4071_HPP

#include <vector>
#include "../AComponent.hpp"
#include "../Igates.hpp"
#include <map>

namespace nts {
    class Comp_4071 : public Igates {
        private:
            const std::vector<Gate> _gates = {
                {1, 2, 3},
                {5, 6, 4},
                {8, 9, 10},
                {12, 13, 11}
            };
        public:
            Comp_4071() = default;
            ~Comp_4071() override = default;
            nts::Tristate compute(std::size_t pin) override;
    };
}

#endif //NANO_1_COMP4071_HPP