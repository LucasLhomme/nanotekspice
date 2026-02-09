/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** False
*/

#include "components/Special/False.hpp"
#include "components/Special/Special.hpp"

namespace nts {
    void False::simulate(std::size_t tick) {
        (void)tick;
    }

    nts::Tristate False::compute(std::size_t pin) {
        if (pin != 1)
            return nts::Undefined;
        return nts::False;
    }

    void False::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
        (void)pin; (void)other; (void)otherPin;
    }

    void False::setValue(nts::Tristate value) {
        (void)value;
    }
}
