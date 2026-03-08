/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** comp_4013
*/

#include "components/advanced_components/comp_4013.hpp"

namespace nts {
    /**
     * \brief Initialize internal flip-flop outputs and clock memories.
     */
    Comp_4013::Comp_4013() {
        _output1 = nts::Undefined;
        _noutput1 = nts::Undefined;
        _lastClock1 = nts::Undefined;
        _output2 = nts::Undefined;
        _noutput2 = nts::Undefined;
        _lastClock2 = nts::Undefined;
    }

    /**
     * \brief Update internal flip-flops based on their clock/set/reset/data inputs.
     *
     * @param tick Simulation tick (unused).
     */
    void Comp_4013::simulate(std::size_t tick) {
        (void)tick;
        nts::Tristate clock1 = getLinkValue(3);
        nts::Tristate reset1 = getLinkValue(4);
        nts::Tristate data1  = getLinkValue(5);
        nts::Tristate set1   = getLinkValue(6);
        updateFlipFlop(data1, clock1, set1, reset1, _output1, _noutput1, _lastClock1);
        nts::Tristate set2   = getLinkValue(8);
        nts::Tristate data2  = getLinkValue(9);
        nts::Tristate reset2 = getLinkValue(10);
        nts::Tristate clock2 = getLinkValue(11);
        updateFlipFlop(data2, clock2, set2, reset2, _output2, _noutput2, _lastClock2);
    }

    /**
     * \brief Helper returning logical NOT for Tristate, preserving Undefined.
     */
    static nts::Tristate logicNot(nts::Tristate value) {
        if (value == nts::Undefined)
            return nts::Undefined;
        return (value == nts::True) ? nts::False : nts::True;
    }

    /**
     * \brief Update a single flip-flop's outputs based on control signals.
     *
     * @param data Data input.
     * @param clock Clock input.
     * @param set Set input.
     * @param reset Reset input.
     * @param output Reference to store direct output.
     * @param noutput Reference to store negated output.
     * @param lastClock Reference to last clock state for edge detection.
     */
    void Comp_4013::updateFlipFlop(nts::Tristate data, nts::Tristate clock, nts::Tristate set, nts::Tristate reset, nts::Tristate &output, nts::Tristate &noutput, nts::Tristate &lastClock) {
        bool isRisingEdge = (clock == nts::True && lastClock == nts::False);
        lastClock = clock;

        if (set == nts::True || reset == nts::True) {
            output = (set == nts::True) ? nts::True : nts::False;
            noutput = (reset == nts::True) ? nts::True : nts::False;
            if (set == nts::True && reset == nts::True) {
                output = nts::True;
                noutput = nts::True;
            }
            return;
        }
        if (set == nts::Undefined || reset == nts::Undefined) {
            output = nts::Undefined;
            noutput = nts::Undefined;
            return;
        }
        if (isRisingEdge) {
            output = data;
            noutput = logicNot(data);
        }
    }

    /**
     * \brief Return outputs for flip-flop pins or forward other pin queries.
     *
     * @param pin Pin number to query.
     * @return Corresponding Tristate value.
     */
    nts::Tristate Comp_4013::compute(std::size_t pin) {
        switch (pin) {
            case 1:  return _output1;
            case 2:  return _noutput1;
            case 13: return _output2;
            case 12: return _noutput2;
            default: return getLinkValue(pin); 
        }
    }
}