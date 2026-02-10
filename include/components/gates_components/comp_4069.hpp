/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Comp_4069
*/

#ifndef NANO_1_COMP4069_HPP
#define NANO_1_COMP4069_HPP

#include "Igates.hpp"
#include <map>

namespace nts {
    class Comp_4069 : public Igates {
        private:
            std::map<std::size_t, std::pair<nts::IComponent*, std::size_t>> _links;
        public:
            Comp_4069() = default;
            ~Comp_4069() override = default;
            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
    };
}


#endif //NANO_1_COMP4069_HPP