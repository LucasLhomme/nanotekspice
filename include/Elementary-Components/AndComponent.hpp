/*
** EPITECH PROJECT, 2026
** nano
** File description:
** AndComponent
*/

#ifndef ANDCOMPONENT_HPP_
    #define ANDCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts {
    class AndComponent : public nts::AComponent {
        public:
            AndComponent();
            ~AndComponent() noexcept override = default;

            nts::Tristate compute(std::size_t pin) override;
    };
}

#endif /* !ANDCOMPONENT_HPP_ */
