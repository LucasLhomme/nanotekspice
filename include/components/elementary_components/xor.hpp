//
// Created by crabe on 09/02/2026.
//

#ifndef NANO_1_XOR_HPP
#define NANO_1_XOR_HPP

#include "IElementary.hpp"
#include <cstddef>

namespace nts {
    class Xor : public IElementary {
    private:
        nts::IComponent* _links[4];
        std::size_t _linkPins[4];
    public:
        Xor();
        ~Xor() override = default;
        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        ComponentType getType() const override;
    };
} // nts

#endif //NANO_1_XOR_HPP