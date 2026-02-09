/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** True
*/

#ifndef NANO_1_TRUE_HPP
#define NANO_1_TRUE_HPP

#include <cstddef>
#include "IComponent.hpp"
#include "Special.hpp"

namespace nts {
    class True : public Special {
    public:
        True() = default;
        ~True() override = default;
        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;

        void setValue(nts::Tristate value);
    };
}

#endif //NANO_1_TRUE_HPP