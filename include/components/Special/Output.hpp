/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Output
*/

#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include "IComponent.hpp"
#include "components/AComponent.hpp"

namespace nts {
    class Output : public AComponent {
        private:
            nts::Tristate _value;
        public:
            Output();
            ~Output() override = default;
            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin) override;
    };
}
#endif