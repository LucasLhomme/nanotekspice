/*
** EPITECH PROJECT, 2026
** nano
** File description:
** TrueComponent
*/

#ifndef NANO_TrueComponent_HPP
    #define NANO_TrueComponent_HPP

#include "AComponent.hpp"

namespace nts {
    class TrueComponent : public nts::AComponent {
    public:
        ~TrueComponent() noexcept override = default;

        nts::Tristate compute(std::size_t pin) override;
    };
}

#endif //NANO_TrueComponent_HPP
