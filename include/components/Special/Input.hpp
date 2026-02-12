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
        public:
            Input();
            ~Input() override = default;
            nts::Tristate compute(std::size_t pin) override;
            void setValue(nts::Tristate value);
    };
}
#endif