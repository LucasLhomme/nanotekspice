/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** AComponent
*/

#ifndef NANO_1_ACOMPONENT_HPP
#define NANO_1_ACOMPONENT_HPP

#include "IComponent.hpp"
#include <map>
#include <vector>
#include <utility>

namespace nts {
    class AComponent : public IComponent {
        protected:
            std::multimap<std::size_t, std::pair<nts::IComponent*, std::size_t>> _links;
            nts::Tristate computeSafe(nts::IComponent *other, std::size_t pin);
            nts::Tristate getLinkValue(std::size_t pin);
            std::pair<nts::IComponent*, std::size_t> getLink(std::size_t pin) const;

        public:
            virtual ~AComponent() = default;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void simulate(std::size_t tick) override;
            static int recursionDepth;
    };
}
#endif