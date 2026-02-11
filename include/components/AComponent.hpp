#ifndef NANO_1_ACOMPONENT_HPP
#define NANO_1_ACOMPONENT_HPP

#include "IComponent.hpp"
#include <map>

namespace nts {
    class AComponent : public IComponent {
        protected:
            std::map<std::size_t, std::pair<nts::IComponent*, std::size_t>> _links;
        public:
            virtual ~AComponent() = default;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin) override = 0;
    };
}
#endif