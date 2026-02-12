/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** comp_4071 Implementation
*/

#include "components/gates_components/comp_4071.hpp"

namespace nts {
    nts::Tristate Comp_4071::computeOr(std::size_t pinA, std::size_t pinB)
    {
        nts::Tristate valueA = nts::Undefined;
        nts::Tristate valueB = nts::Undefined;

        if (_links.find(pinA) != _links.end()) {
            auto link = _links[pinA];
            valueA = link.first->compute(link.second);
        }
        if (_links.find(pinB) != _links.end()) {
            auto link = _links[pinB];
            valueB = link.first->compute(link.second);
        }
        if (valueA == nts::True || valueB == nts::True)
            return nts::True;
        if (valueA == nts::False && valueB == nts::False)
            return nts::False;
        return nts::Undefined;
    }

    nts::Tristate Comp_4071::compute(std::size_t pin)
    {
        switch (pin) {
            case 3:
                return computeOr(1, 2);
            case 4:
                return computeOr(5, 6);
            case 10:
                return computeOr(8, 9);
            case 11:
                return computeOr(12, 13);
            default:
                return nts::Undefined;
        }
    }

}