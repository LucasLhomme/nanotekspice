/*
** EPITECH PROJECT, 2026
** nano
** File description:
** Clock
*/

#ifndef NANO_CLOCK_HPP
    #define NANO_CLOCK_HPP

#include "AComponent.hpp"

class Clock : public nts::AComponent {
public:
    Clock(std::string name);
    ~Clock() override = default;

    void setValue(nts::Tristate value);

    void simulate(std::size_t tick) override;
    nts::Tristate compute(std::size_t pin) override;

private:
    nts::Tristate _value = nts::Undefined;
    nts::Tristate _nextValue = nts::Undefined;
};

#endif //NANO_CLOCK_HPP
