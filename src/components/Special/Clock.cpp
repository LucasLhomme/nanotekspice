/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Clock Implementation
*/

#include "components/Special/Clock.hpp"

namespace nts {

    Clock::Clock() {
        _value = nts::Undefined;
    }

    void Clock::simulate(std::size_t tick)
    {
        (void)tick;

        if (_value == nts::True) {
            _value = nts::False;
        } else if (_value == nts::False) {
            _value = nts::True;
        } else
            _value = nts::Undefined;
    }

    nts::Tristate Clock::compute(std::size_t pin)
    {
        if (pin != 1)
            return nts::Undefined;
        return _value;
    }

    void Clock::setValue(nts::Tristate value)
    {
        _value = value;
    }
}