/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Clock Header
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include "../IComponent.hpp"

namespace nts {
    class Clock : public IComponent {
    private:
        nts::Tristate _value;
        nts::Tristate _nextValue;
    public:
        Clock();
        ~Clock() override = default;
        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        ComponentType getType() const override;
        void setValue(nts::Tristate value);
    };
}

#endif /* !CLOCK_HPP_ */