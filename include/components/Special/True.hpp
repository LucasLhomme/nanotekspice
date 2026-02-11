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
#include "AComponent.hpp"

namespace nts {
    class True : public AComponent {
    public:
        True() = default;
        ~True() override = default;
        Tristate compute(std::size_t pin) override;
        void setValue(nts::Tristate value);
    };
}

#endif //NANO_1_TRUE_HPP