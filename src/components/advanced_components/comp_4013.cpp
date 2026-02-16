/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** comp_4013
*/

#include "components/advanced_components/comp_4013.hpp"

namespace nts {
    Comp_4013::Comp_4013() {
        _output1 = nts::Undefined;
        _noutput1 = nts::Undefined;
        _lastClock1 = nts::Undefined;
        _output2 = nts::Undefined;
        _noutput2 = nts::Undefined;
        _lastClock2 = nts::Undefined;
    }

    void Comp_4013::simulate(std::size_t tick) {
        (void)tick;
        nts::Tristate clock1 = computeSafe(_links[3].first, _links[3].second);
        nts::Tristate reset1 = computeSafe(_links[4].first, _links[4].second);
        nts::Tristate data1 = computeSafe(_links[5].first, _links[5].second);
        nts::Tristate set1 = computeSafe(_links[6].first, _links[6].second);
        updateFlipFlop(data1, clock1, set1, reset1, _output1, _noutput1, _lastClock1);
        nts::Tristate set2 = computeSafe(_links[8].first, _links[8].second);
        nts::Tristate data2 = computeSafe(_links[9].first, _links[9].second);
        nts::Tristate reset2 = computeSafe(_links[10].first, _links[10].second);
        nts::Tristate clock2 = computeSafe(_links[11].first, _links[11].second);
        updateFlipFlop(data2, clock2, set2, reset2, _output2, _noutput2, _lastClock2);
    }

    static nts::Tristate logicNot(nts::Tristate value) {
        if (value == nts::Undefined)
            return nts::Undefined;
        return (value == nts::True) ? nts::False : nts::True;
    }


    void Comp_4013::updateFlipFlop(nts::Tristate data, nts::Tristate clock, nts::Tristate set, nts::Tristate reset, nts::Tristate &output, nts::Tristate &noutput, nts::Tristate &lastClock) {
        bool isRisingEdge = (clock == nts::True && lastClock != nts::True);
        lastClock = clock;

        if (set == nts::True) {
            output = nts::True;
            noutput = (reset == nts::True) ? nts::True : nts::False;
            return;
        }
        if (reset == nts::True) {
            output = nts::False;
            noutput = nts::True;
            return;
        }
        if (isRisingEdge) {
            output = data;
            noutput = logicNot(data);
        }
    }

    nts::Tristate Comp_4013::compute(std::size_t pin) {
        switch (pin) {
            case 1:
                return _output1;
            case 2:
                return _noutput1;
            case 13:
                return _output2;
            case 12:
                return _noutput2;
            default:
                return nts::Undefined;
        }
    }
}