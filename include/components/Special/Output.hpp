/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Output
*/

#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include "IComponent.hpp"
#include "AComponent.hpp"

namespace nts {
    class Output : public AComponent {
        public:
            Output();
            ~Output() override = default;
            nts::Tristate compute(std::size_t pin) override;
    };
}
#endif