/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Comp_4069
*/

#ifndef NANO_1_COMP4069_HPP
#define NANO_1_COMP4069_HPP

#include "../Igates.hpp"
#include "../AComponent.hpp"
#include <vector>
#include <map>

namespace nts {
    class Comp_4069 : public Igates {
        private:
            const std::vector<Gate> _gates = {
                {1, 0, 2},
                {3, 0, 4},
                {5, 0, 6},
                {9, 0, 8},
                {11, 0, 10},
                {13, 0, 12}
            };
        public:
            Comp_4069() = default;
            ~Comp_4069() override = default;
            nts::Tristate compute(std::size_t pin) override;
    };
}


#endif //NANO_1_COMP4069_HPP