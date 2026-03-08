/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Clock Implementation
*/

#include "components/Special/Clock.hpp"

namespace nts {

    /**
     * \brief Initialize a Clock with undefined state.
     */
    Clock::Clock() {
        _value = nts::Undefined;
        _nextValue = nts::Undefined;
    }

    /**
     * \brief Toggle or advance the clock state on simulation.
     *
     * @param tick Current simulation tick (unused).
     */
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

    /**
     * \brief Return the current clock value on pin 1.
     *
     * @param pin Pin number to read (only 1 is valid).
     * @return Current clock Tristate value or Undefined for invalid pins.
     */
    nts::Tristate Clock::compute(std::size_t pin)
    {
        if (pin != 1)
            return nts::Undefined;
        return _value;
    }

    /**
     * \brief Schedule a value for the clock to take on next simulate().
     *
     * @param value Tristate value to set as next state.
     */
    void Clock::setValue(nts::Tristate value)
    {
        _nextValue = value;
    }
}