#include "../../../include/components/advanced_components/comp_4017.hpp"

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
        int targetCount = -1;
        switch (pin) {
            case 3:  targetCount = 0; break; // Q0
            case 2:  targetCount = 1; break; // Q1
            case 4:  targetCount = 2; break; // Q2
            case 7:  targetCount = 3; break; // Q3
            case 10: targetCount = 4; break; // Q4
            case 1:  targetCount = 5; break; // Q5
            case 5:  targetCount = 6; break; // Q6
            case 6:  targetCount = 7; break; // Q7
            case 9:  targetCount = 8; break; // Q8
            case 11: targetCount = 9; break; // Q9
            case 12: 
                if (_count <= 4)
                    return nts::True;
                else
                    return nts::False;
            
            default: return nts::Undefined;
        }
        if (_count == targetCount) {
            return nts::True;
        } else {
            return nts::False;
        }
    }
}