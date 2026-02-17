/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** and
*/

#include "../../../include/components/elementary_components/and.hpp"
#include "../../../include/Exception.hpp"

namespace nts {

    And::And() {}

    nts::Tristate And::compute(std::size_t pin)
    {
        if (pin != 3)
            return nts::Undefined;
        if (_links.find(1) == _links.end() || _links.find(2) == _links.end())
            throw Exception("And gate missing input link");
        nts::Tristate a = computeSafe(_links[1].first, _links[1].second);
        nts::Tristate b = computeSafe(_links[2].first, _links[2].second);
        return a && b;
    }
}

