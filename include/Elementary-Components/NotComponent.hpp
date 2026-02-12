/*
** EPITECH PROJECT, 2026
** nano
** File description:
** NotComponent
*/

#ifndef NOTCOMPONENT_HPP_
    #define NOTCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts {
    class NotComponent : public nts::AComponent {
        public:
            NotComponent();
            ~NotComponent() noexcept override = default;
    
            nts::Tristate compute(std::size_t pin) override;
    };
}

#endif /* !NOTCOMPONENT_HPP_ */
