/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Output
*/

#include "components/Special/Output.hpp"
#include "components/Special/Special.hpp"

namespace nts {
    Output::Output() : _link(nullptr), _linkPin(0) {}

    void Output::simulate(std::size_t tick) {
        (void)tick;
    }

    nts::Tristate Output::compute(std::size_t pin) {
        if (pin != 1 || _link == nullptr)
			return nts::Undefined;
        return _link->compute(_linkPin);
    }

    void Output::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
        if (pin != 1)
			return;
        _link = &other;
        _linkPin = otherPin;
    }
}