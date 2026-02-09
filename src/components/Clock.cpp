/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Clock Implementation
*/

#include "../../include/components/Clock.hpp"

namespace nts {

    Clock::Clock() : _value(nts::Undefined)
    {
    }

    void Clock::simulate(std::size_t tick)
    {
        (void)tick;

        if (_value == nts::True) {
            _value = nts::False;
        } else if (_value == nts::False) {
            _value = nts::True;
        }
    }

    nts::Tristate Clock::compute(std::size_t pin)
    {
        if (pin != 1)
            return nts::Undefined;
        return _value;
    }

    void Clock::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
    {
        (void)pin;
        (void)other;
        (void)otherPin;
    }

    void Clock::setValue(nts::Tristate value)
    {
        _value = value;
    }

    nts::ComponentType Clock::getType() const
    {
        return nts::ComponentType::CLOCK;
    }
}