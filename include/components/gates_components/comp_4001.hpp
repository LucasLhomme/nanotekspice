/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** comp_4001 Header
*/

#ifndef NANO_1_COMP4001_HPP
#define NANO_1_COMP4001_HPP

#include "../AComponent.hpp"
#include <map>

namespace nts {
    class Comp_4001 : public AComponent {
    private:
        nts::Tristate computeNor(std::size_t pinA, std::size_t pinB);
    public:
        Comp_4001() = default;
        ~Comp_4001() override = default;
        nts::Tristate compute(std::size_t pin) override;
    };
}

#endif //NANO_1_COMP4001_HPP