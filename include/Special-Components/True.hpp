/*
** EPITECH PROJECT, 2026
** nano
** File description:
** True
*/

#ifndef NANO_TRUE_HPP
#define NANO_TRUE_HPP

#include "AComponent.hpp"

class True : public nts::AComponent {
public:
    ~True() override = default;

    void simulate(std::size_t tick) override;
    nts::Tristate compute(std::size_t pin) override;

private:
    nts::Tristate _value = nts::Undefined;
};

#endif //NANO_TRUE_HPP
