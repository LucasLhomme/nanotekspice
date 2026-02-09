//
// Created by crabe on 09/02/2026.
//

#ifndef NANO_1_AND_HPP
#define NANO_1_AND_HPP

#include <cstddef>
#include "IElementary.hpp"

namespace nts {
    class And : public IElementary {
    private:
        nts::IComponent* _links[4];
        std::size_t _linkPins[4];
    public:
        And();
        ~And() override = default;
        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        ComponentType getType() const override;
    };
} // nts

#endif //NANO_1_AND_HPP