/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** comp_4040 Implementation
*/

#include "components/advanced_components/comp_4040.hpp"

namespace nts {

    /**
     * \brief Initialize the 4040 binary counter state.
     */
    Comp_4040::Comp_4040() {
        _counter = -1; 
        _prevClock = nts::Undefined;
    }

    /**
     * \brief Increment or reset the internal counter based on clock/reset pins.
     *
     * @param tick Simulation tick (unused).
     */
    void Comp_4040::simulate(std::size_t tick) {
        (void)tick;
        nts::Tristate clock = getLinkValue(10);
        nts::Tristate reset = getLinkValue(11);

        if (reset == nts::True)
            _counter = 0;
        else if (reset == nts::Undefined)
            _counter = -1;
        else {
            if (_prevClock == nts::True && clock == nts::False) {
                if (_counter != -1) { 
                    _counter++;
                    if (_counter > 4095)
                        _counter = 0;
                }
            }
        }
        _prevClock = clock;
    }

    /**
     * \brief Return the state of the requested counter output bit.
     *
     * @param pin Pin number to query.
     * @return True/False for the bit or Undefined if counter unset.
     */
    nts::Tristate Comp_4040::compute(std::size_t pin) {
        int bitIndex = -1;

        switch (pin) {
            case 9:  bitIndex = 0; break;
            case 7:  bitIndex = 1; break;
            case 6:  bitIndex = 2; break;
            case 5:  bitIndex = 3; break;
            case 3:  bitIndex = 4; break;
            case 2:  bitIndex = 5; break;
            case 4:  bitIndex = 6; break;
            case 13: bitIndex = 7; break;
            case 12: bitIndex = 8; break;
            case 14: bitIndex = 9; break;
            case 15: bitIndex = 10; break;
            case 1:  bitIndex = 11; break;
            default: return getLinkValue(pin); 
        }
        if (_counter == -1)
            return nts::Undefined;
        if ((_counter >> bitIndex) & 1) {
            return nts::True;
        } else {
            return nts::False;
        }
    }
}