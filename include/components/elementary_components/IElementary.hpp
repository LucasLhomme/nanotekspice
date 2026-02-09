//
// Created by crabe on 09/02/2026.
//

#ifndef NANO_1_IELEMENTARY_HPP
#define NANO_1_IELEMENTARY_HPP

#include "../../IComponent.hpp"

namespace nts {
    class IElementary : public IComponent {
     public:
        ~IElementary() override = default;
     protected:
        IElementary() = default;
    };
} // nts

#endif //NANO_1_IELEMENTARY_HPP