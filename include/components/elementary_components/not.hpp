/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** not
*/

#ifndef NOT_COMPONENT_HPP_
#define NOT_COMPONENT_HPP_

#include "IComponent.hpp"
#include <map>

namespace nts {
    class Not : public IComponent {
        private:
            std::map<std::size_t, std::pair<nts::IComponent*, std::size_t>> _links;
        public:
            Not() = default;
            ~Not() override = default;
            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
    };
}

#endif /* !NOT_COMPONENT_HPP_ */