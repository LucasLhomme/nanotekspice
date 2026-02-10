/*
** EPITECH PROJECT, 2026
** nano
** File description:
** False
*/

#ifndef NANO_FALSE_HPP
#define NANO_FALSE_HPP

#include "AComponent.hpp"

class False : public nts::AComponent {
public:
    ~False() override = default;

    void simulate(std::size_t tick) override;
    nts::Tristate compute(std::size_t pin) override;

private:
    nts::Tristate _value = nts::Undefined;
};

#endif //NANO_FALSE_HPP
