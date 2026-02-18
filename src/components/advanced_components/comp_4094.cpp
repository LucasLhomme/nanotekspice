/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** comp_4094
*/

#include "components/advanced_components/comp_4094.hpp"

namespace nts {

    Comp_4094::Comp_4094()
    {
        _count = 0;
        _prevClock = nts::Undefined;
    }

    nts::Tristate Comp_4094::compute(std::size_t pin)
    {
        (void)pin;
        return nts::Undefined;
    }

    void Comp_4094::simulate(std::size_t tick)
    {
        (void)tick;
    }

} // namespace nts