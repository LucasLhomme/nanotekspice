/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** comp_4094
*/

#ifndef COMP_4094_HPP_
#define COMP_4094_HPP_

#include "components/advanced_components/AdvancedComponent.hpp"

namespace nts {
    class Comp_4094 : public AdvancedComponent {
    private:
        int _count;
        nts::Tristate _prevClock;
    public:
        Comp_4094();
        ~Comp_4094() override = default;

        nts::Tristate compute(std::size_t pin) override;
        void simulate(std::size_t tick) override;
    };
}

#endif /* !COMP_4094_HPP_ */
