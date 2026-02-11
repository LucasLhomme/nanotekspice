/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** not
*/

#ifndef NOT_COMPONENT_HPP_
#define NOT_COMPONENT_HPP_

#include "AComponent.hpp"
#include <map>

namespace nts {
    class Not : public AComponent {
        public:
            Not() = default;
            ~Not() override = default;
            nts::Tristate compute(std::size_t pin) override;
    };
}

#endif /* !NOT_COMPONENT_HPP_ */