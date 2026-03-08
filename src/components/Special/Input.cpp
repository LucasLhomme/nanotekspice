/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Input
*/

#include "components/Special/Input.hpp"

namespace nts {
    /**
     * \brief Construct an Input with undefined initial value.
     */
    Input::Input() : _value(nts::Undefined), _nextValue(nts::Undefined) {}

    /**
     * \brief Apply the next value to the current value at simulation step.
     *
     * @param tick Simulation tick (ignored in Input).
     */
    void Input::simulate(std::size_t tick) {
        (void)tick;
        _value = _nextValue;
    }

    /**
     * \brief Return the current value on pin 1.
     *
     * @param pin Pin number to read (only 1 is valid).
     * @return Current Tristate value or Undefined for invalid pins.
     */
    nts::Tristate Input::compute(std::size_t pin) {
        if (pin != 1)
            return nts::Undefined;
        return _value;
    }

    /**
     * \brief Schedule a new value to be applied on next simulation.
     *
     * @param value Tristate value to set (1,0 or U).
     */
    void Input::setValue(nts::Tristate value) {
        _nextValue = value;
    }
}