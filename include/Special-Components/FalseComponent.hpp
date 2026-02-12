/*
** EPITECH PROJECT, 2026
** nano
** File description:
** FalseComponent
*/

#ifndef NANO_FalseComponent_HPP
    #define NANO_FalseComponent_HPP

#include "AComponent.hpp"

namespace nts {
    class FalseComponent : public nts::AComponent {
        public:
            ~FalseComponent() noexcept override = default;

            nts::Tristate compute(std::size_t pin) override;
    };
}

#endif //NANO_FalseComponent_HPP
