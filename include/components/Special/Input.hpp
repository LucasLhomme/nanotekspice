/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Input
*/

#ifndef INPUT_HPP
#define INPUT_HPP

#include "IComponent.hpp"
#include "components/AComponent.hpp"

namespace nts {
    class Input : public AComponent {
        private:
            nts::Tristate _value;
            nts::Tristate _nextValue;
        public:
            Input();
            ~Input() override = default;
            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin) override;
            void setValue(nts::Tristate value);
    };
}
#endif