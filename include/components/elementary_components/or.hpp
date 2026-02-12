/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** or
*/

#ifndef OR_COMPONENT_HPP
#define OR_COMPONENT_HPP

#include "components/AComponent.hpp"
#include <map>

namespace nts {
    class Or : public AComponent {
        public:
            Or();
            ~Or() override = default;
            nts::Tristate compute(std::size_t pin) override;
    };
}
#endif