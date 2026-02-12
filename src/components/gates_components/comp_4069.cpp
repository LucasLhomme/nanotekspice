/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Gate4069
*/

#include "components/gates_components/comp_4069.hpp"

namespace nts {
    nts::Tristate Comp_4069::compute(std::size_t pin)
    {
        std::size_t inputPin = 0;

        switch (pin) {
            case 2:
				inputPin = 1;
				break;
            case 4:
				inputPin = 3;
				break;
            case 6:
				inputPin = 5;
				break;
            case 8:
				inputPin = 9;
				break;
            case 10:
				inputPin = 11;
				break;
            case 12:
				inputPin = 13;
				break;
            default: return nts::Undefined;
        }
        if (_links.find(inputPin) == _links.end())
            return nts::Undefined;
        auto link = _links[inputPin];
        nts::Tristate val = link.first->compute(link.second);
        if (val == nts::True)
			return nts::False;
        if (val == nts::False)
			return nts::True;
        return nts::Undefined;
    }
}