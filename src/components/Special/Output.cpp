/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Output
*/

#include "components/Special/Output.hpp"

namespace nts {
    Output::Output() : _value(nts::Undefined) {}

    void Output::simulate(std::size_t tick) {
        (void)tick;
        if (_links.find(1) != _links.end()) {
            _value = computeSafe(_links[1].first, _links[1].second);
        } else {
            _value = nts::Undefined;
        }
    }

    nts::Tristate Output::compute(std::size_t pin) {
        if (pin != 1)
            return nts::Undefined;
        return _value;
    }
}