/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Clock Header
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include "IComponent.hpp"
#include "components/AComponent.hpp"

namespace nts {
    class Clock : public AComponent {
    private:
        nts::Tristate _value;
    public:
        Clock();
        ~Clock() override = default;
        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        void setValue(nts::Tristate value);
    };
}

#endif /* !CLOCK_HPP_ */