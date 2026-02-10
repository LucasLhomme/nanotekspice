/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** comp_4071 Header
*/

#ifndef NANO_1_COMP4071_HPP
#define NANO_1_COMP4071_HPP

#include "Igates.hpp"
#include <map>

namespace nts {
    class Comp_4071 : public IComponent {
        private:
            std::map<std::size_t, std::pair<nts::IComponent*, std::size_t>> _links;
            nts::Tristate computeOr(std::size_t pinA, std::size_t pinB);
        public:
            Comp_4071() = default;
            ~Comp_4071() override = default;
            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
    };
}

#endif //NANO_1_COMP4071_HPP