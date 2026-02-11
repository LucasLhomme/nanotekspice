/*
** EPITECH PROJECT, 2026
** nano
** File description:
** OutputComponent
*/

#ifndef NANO_OutputComponent_HPP
    #define NANO_OutputComponent_HPP

#include "AComponent.hpp"

namespace nts {
    class OutputComponent : public nts::AComponent {
    public:
        OutputComponent(std::string name);
        ~OutputComponent() noexcept override = default;

        nts::Tristate compute(std::size_t pin) override;
    };
} 

#endif //NANO_OutputComponent_HPP
