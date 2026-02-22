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
        _nextValue = nts::Undefined;
    }

    void Clock::simulate(std::size_t tick)
    {
        (void)tick;
        _value = _nextValue;
        if (_value == nts::True) {
            _nextValue = nts::False;
        } else if (_value == nts::False) {
            _nextValue = nts::True;
        } else {
            _nextValue = nts::Undefined;
        }
    }

    nts::Tristate Clock::compute(std::size_t pin)
    {
        if (pin != 1)
            return nts::Undefined;
        return _value;
    }

    void Clock::setValue(nts::Tristate value)
    {
        _nextValue = value;
    }
}