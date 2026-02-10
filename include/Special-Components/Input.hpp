/*
** EPITECH PROJECT, 2026
** nano
** File description:
** Input
*/

#ifndef NANO_INPUT_HPP
    #define NANO_INPUT_HPP

#include "AComponent.hpp"

#include "AComponent.hpp"

class Input : public nts::AComponent {
public:
    Input(std::string name);
    ~Input() override = default;

    void setValue(nts::Tristate value);

    void simulate(std::size_t tick) override;
    nts::Tristate compute(std::size_t pin) override;

private:
    nts::Tristate _value = nts::Undefined;
};

#endif //NANO_INPUT_HPP
