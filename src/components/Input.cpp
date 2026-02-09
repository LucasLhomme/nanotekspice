/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Input
*/

#include "../../include/components/Input.hpp"

namespace nts {
    Input::Input() : _value(nts::Undefined) {}

    void Input::simulate(std::size_t tick) {
        (void)tick; 
    }

    nts::Tristate Input::compute(std::size_t pin) {
        if (pin != 1)
			return nts::Undefined;
        return _value;
    }

    void Input::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
        (void)pin; (void)other; (void)otherPin;
    }

    void Input::setValue(nts::Tristate value) {
        _value = value;
    }

    nts::ComponentType nts::Input::getType() const {
        return nts::ComponentType::INPUT;
    }
}