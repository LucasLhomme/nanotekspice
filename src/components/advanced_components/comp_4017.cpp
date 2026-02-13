/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** comp_4017
*/

#include "components/advanced_components/comp_4017.hpp"
#include <array>


namespace nts {

    Comp_4017::Comp_4017() {
        _count = 0;
        _prevClock = nts::Undefined;
    }

    nts::Tristate Comp_4017::getVal(std::size_t pin) {
        if (_links.find(pin) == _links.end())
            return nts::Undefined;
        return _links[pin].first->compute(_links[pin].second);
    }

    void Comp_4017::simulate(std::size_t tick) {
        (void)tick;
        nts::Tristate clock = getVal(14);   // CP0
        nts::Tristate inhibit = getVal(13); // CP1
        nts::Tristate reset = getVal(15);   // MR

        if (reset == nts::True) {
            _count = 0;
            _prevClock = clock;
            return;
        }
        if (inhibit == nts::True) {
            _prevClock = clock;
            return;
        }
        if (_prevClock == nts::False && clock == nts::True) {
            _count++;
            if (_count > 9) {
                _count = 0;
            }
        }
        _prevClock = clock;
    }

    nts::Tristate Comp_4017::compute(std::size_t pin) {

        static const std::array<int, 16> pinToCount =
            // -1 = unused, -2 = special case for pin 12 and 0-4 = true, 5-9 = false
            { -1, 5, 1, 0, 2, 6, 7, 3, -1, 8, 4, 9, -2, -1, -1, -1 };

        if (pin >= pinToCount.size())
            return nts::Undefined;
        int mapVal = pinToCount[pin];
        if (mapVal == -1)
            return nts::Undefined;
        if (mapVal == -2) {
            if (_count <= 4)
                return nts::True;
            return nts::False;
        }
        if (_count == mapVal)
            return nts::True;
        return nts::False;
    }
}