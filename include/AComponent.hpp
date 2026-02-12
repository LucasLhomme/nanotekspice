/*
** EPITECH PROJECT, 2026
** nano
** File description:
** AComponent
*/

#ifndef NANO_ACOMPONENT_HPP
#define NANO_ACOMPONENT_HPP

#include "IComponent.hpp"
#include <map>
#include <vector>

namespace nts {
    class AComponent : public nts::IComponent {
    public:
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        void simulate(std::size_t tick) override;
        virtual nts::Tristate compute(std::size_t pin) override = 0;
        nts::Tristate getLink(std::size_t pin);

    protected:
        std::map<std::size_t, std::vector<std::pair<nts::IComponent*, std::size_t>>> _links;
    };
}

#endif //NANO_ACOMPONENT_HPP
