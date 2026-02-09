/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Input
*/

#ifndef INPUT_HPP
#define INPUT_HPP

#include "IComponent.hpp"

namespace nts {
    class Input : public IComponent {
        private:
            nts::Tristate _value;
        public:
            Input();
            ~Input() override = default;
            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            ComponentType getType() const override;
            void setValue(nts::Tristate value);
    };
}
#endif