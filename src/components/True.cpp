//
// Created by crabe on 09/02/2026.
//

#include "../../include/components/True.hpp"

namespace nts {
    void True::simulate(std::size_t tick) {
        (void)tick;
    }

    nts::Tristate True::compute(std::size_t pin) {
        if (pin != 1)
            return nts::Undefined;
        return nts::True;
    }

    void True::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
        (void)pin; (void)other; (void)otherPin;
    }

    ComponentType True::getType() {
        return nts::ComponentType::TRUE;
    }

    void True::setValue(nts::Tristate value) {
        nts::Tristate result = value;
    }
}
