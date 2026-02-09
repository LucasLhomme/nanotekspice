/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** True
*/

#include "components/Special/True.hpp"
#include "components/Special/Special.hpp"

namespace nts {
    void True::simulate(std::size_t tick) {
        (void)tick;
    }

    nts::Tristate True::compute(std::size_t pin) {
        if (pin != 1)
            return nts::Undefined;
        return nts::True;
    }

    void True::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
        (void)pin; (void)other; (void)otherPin;
    }

    void True::setValue(nts::Tristate value) {
        (void)value;
    }
}
