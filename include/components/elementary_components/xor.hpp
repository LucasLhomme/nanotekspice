//
// Created by crabe on 09/02/2026.
//

#ifndef NANO_1_XOR_HPP
#define NANO_1_XOR_HPP

#include "AComponent.hpp"
#include <cstddef>

namespace nts {
    class Xor : public AComponent {
    public:
        Xor();
        ~Xor() override = default;
        Tristate compute(std::size_t pin) override;
    };
}

#endif //NANO_1_XOR_HPP