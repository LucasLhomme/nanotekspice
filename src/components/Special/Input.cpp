/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Input
*/

#include "components/Special/Input.hpp"

namespace nts {
    Input::Input() : _value(nts::Undefined) {}

    nts::Tristate Input::compute(std::size_t pin) {
        if (pin != 1)
			return nts::Undefined;
        return _value;
    }

    void Input::setValue(nts::Tristate value) {
        _value = value;
    }
}