/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** comp_4001 Implementation
*/

#include "components/gates_components/comp_4001.hpp"

namespace nts {
    nts::Tristate Comp_4001::compute(std::size_t pin)
    {
        std::size_t pinA = 0;
        std::size_t pinB = 0;
        switch (pin) {
            case 3:  pinA = 1;  pinB = 2;  break;
            case 4:  pinA = 5;  pinB = 6;  break;
            case 10: pinA = 8;  pinB = 9;  break;
            case 11: pinA = 12; pinB = 13; break;
            default: return nts::Undefined;
        }
        nts::Tristate valueA = nts::Undefined;
        nts::Tristate valueB = nts::Undefined;
        if (_links.find(pinA) != _links.end())
            valueA = computeSafe(_links[pinA].first, _links[pinA].second);
        if (_links.find(pinB) != _links.end())
            valueB = computeSafe(_links[pinB].first, _links[pinB].second);
        return !(valueA || valueB);
    }
}