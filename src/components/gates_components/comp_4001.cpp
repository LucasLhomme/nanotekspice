/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** comp_4001 Implementation
*/

#include "components/gates_components/comp_4001.hpp"

namespace nts {
    nts::Tristate Comp_4001::computeNor(std::size_t pinA, std::size_t pinB)
    {
        nts::Tristate valueA = nts::Undefined;
        nts::Tristate valueB = nts::Undefined;

        if (_links.find(pinA) != _links.end()) {
            auto link = _links[pinA];
            valueA = computeSafe(link.first, link.second);
        }
        if (_links.find(pinB) != _links.end()) {
            auto link = _links[pinB];
            valueB = computeSafe(link.first, link.second);
        }
        if (valueA == nts::True || valueB == nts::True)
            return nts::False;
        if (valueA == nts::False && valueB == nts::False)
            return nts::True;
        return nts::Undefined;
    }

    nts::Tristate Comp_4001::compute(std::size_t pin)
    {
        switch (pin) {
            case 3:
                return computeNor(1, 2);
            case 4:
                return computeNor(5, 6);
            case 10:
                return computeNor(8, 9);
            case 11:
                return computeNor(12, 13);
            default:
                return nts::Undefined;
        }
    }

}