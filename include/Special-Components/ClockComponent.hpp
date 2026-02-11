/*
** EPITECH PROJECT, 2026
** nano
** File description:
** ClockComponent
*/

#ifndef NANO_ClockComponent_HPP
    #define NANO_ClockComponent_HPP

#include "AComponent.hpp"

namespace nts {
    class ClockComponent : public nts::AComponent {
    public:
        ClockComponent(std::string name);
        ~ClockComponent() noexcept override = default;

        void setValue(nts::Tristate value);

        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;

    private:
        nts::Tristate _value = nts::Undefined;
        nts::Tristate _nextValue = nts::Undefined;
    };
}

#endif //NANO_ClockComponent_HPP
