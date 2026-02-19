/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** comp_4094
*/

#include "components/advanced_components/comp_4094.hpp"

namespace nts {

    Comp_4094::Comp_4094()
    {
        _count = 0;
        _prevClock = nts::Undefined;
    }

    nts::Tristate Comp_4094::compute(std::size_t pin)
    {
        static const std::array<size_t, 8> outPins = {4,5,6,7,8,9,10,11};
        for (size_t i = 0; i < outPins.size(); ++i) {
            if (outPins[i] == pin)
                return _outputBuffer[i];
        }
        return nts::Undefined;
    }

    void Comp_4094::simulate(std::size_t tick)
    {
        nts::Tristate oe = getLinkValue(15);
        nts::Tristate clock = getLinkValue(3);
        nts::Tristate strobe = getLinkValue(1);
        nts::Tristate data = getLinkValue(2);

        bool prevLow = (_prevClock == nts::False || _prevClock == nts::Undefined);
        bool nowHigh = (clock == nts::True);
        if (prevLow && nowHigh) {
            for (int i = 7; i > 0; --i)
                _shift[i] = _shift[i-1];
            _shift[0] = data;
        }

        if (strobe == nts::True) {
            _outputBuffer = _shift;
        }

        if (oe != nts::False) {
            _outputBuffer.fill(nts::Undefined);
        }

        _prevClock = clock;
    }
}