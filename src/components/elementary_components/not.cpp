/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** not
*/

#include "components/elementary_components/not.hpp"

namespace nts {

    void Not::simulate(std::size_t tick)
    {
        (void)tick;
    }

    void Not::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
    {
        _links[pin] = std::make_pair(&other, otherPin);
    }

    nts::Tristate Not::compute(std::size_t pin)
    {
        if (pin != 2)
            return nts::Undefined;
        if (_links.find(1) == _links.end())
            return nts::Undefined;
        auto link = _links[1];
        nts::Tristate value = link.first->compute(link.second);
        if (value == nts::True)
            return nts::False;
        if (value == nts::False)
            return nts::True;
        return nts::Undefined;
    }
}