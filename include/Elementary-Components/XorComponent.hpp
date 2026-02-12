/*
** EPITECH PROJECT, 2026
** nano
** File description:
** XorComponent
*/

#ifndef XORCOMPONENT_HPP_
    #define XORCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts {
    class XorComponent : public nts::AComponent {
        public:
            XorComponent();
            ~XorComponent() noexcept override = default;
    
            nts::Tristate compute(std::size_t pin) override;
    };
}

#endif /* !XORCOMPONENT_HPP_ */
