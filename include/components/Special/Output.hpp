/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Output
*/

#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include "IComponent.hpp"
#include "Special.hpp"

namespace nts {
    class Output : public Special {
        private:
            nts::IComponent *_link;
            std::size_t _linkPin;
        public:
            Output();
            ~Output() override = default;
            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
    };
}
#endif