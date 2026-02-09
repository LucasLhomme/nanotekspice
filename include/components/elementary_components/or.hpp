/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** or
*/

#ifndef OR_COMPONENT_HPP
#define OR_COMPONENT_HPP

#include "IElementary.hpp"
#include <map>

namespace nts {
    class Or : public IElementary {
        private:
            std::map<size_t, std::pair<nts::IComponent*, size_t>> _links;
        public:
            Or();
            ~Or() override = default;
            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
    };
}
#endif