/*
** EPITECH PROJECT, 2026
** nano
** File description:
** OrComponent
*/

#ifndef ORCOMPONENT_HPP_
#define ORCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts {
    class OrComponent : public nts::AComponent {
        public:
            OrComponent();
            ~OrComponent() noexcept override = default;
    
            nts::Tristate compute(std::size_t pin) override;
    };
}

#endif /* !ORCOMPONENT_HPP_ */
