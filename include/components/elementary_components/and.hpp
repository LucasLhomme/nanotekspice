//
// Created by crabe on 09/02/2026.
//

#ifndef NANO_1_AND_HPP
#define NANO_1_AND_HPP

#include <cstddef>
#include "components/AComponent.hpp"

namespace nts {
    class And : public AComponent {
    public:
        And();
        ~And() override = default;
        Tristate compute(std::size_t pin) override;
    };
}

#endif //NANO_1_AND_HPP