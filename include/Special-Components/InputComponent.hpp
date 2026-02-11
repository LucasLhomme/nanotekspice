/*
** EPITECH PROJECT, 2026
** nano
** File description:
** InputComponent
*/

#ifndef NANO_InputComponent_HPP
    #define NANO_InputComponent_HPP

#include "AComponent.hpp"

namespace nts {
    class InputComponent : public nts::AComponent {
    public:
        InputComponent(std::string name);
        ~InputComponent() noexcept override = default;

        void setValue(nts::Tristate value);

        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;

    private:
        nts::Tristate _value = nts::Undefined;
        nts::Tristate _nextValue = nts::Undefined;
    };
}

#endif //NANO_InputComponent_HPP
