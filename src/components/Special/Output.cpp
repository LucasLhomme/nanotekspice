/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Output
*/

#include "components/Special/Output.hpp"

namespace nts {
    Output::Output() {}

    nts::Tristate Output::compute(std::size_t pin) {
        if (pin != 1)
			return nts::Undefined;
        if (_links.find(1) == _links.end())
            return nts::Undefined;
        return _links[1].first->compute(_links[1].second);
    }
}