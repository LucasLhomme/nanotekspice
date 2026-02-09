//
// Created by crabe on 09/02/2026.
//

#include "components/False.hpp"

namespace nts {
    void False::simulate(std::size_t tick) {
        (void)tick;
    }

    nts::Tristate False::compute(std::size_t pin) {
        if (pin != 1)
            return nts::Undefined;
        return nts::False;
    }

    void False::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
        (void)pin; (void)other; (void)otherPin;
    }

    ComponentType False::getType() {
        return nts::ComponentType::FALSE;
    }

    void False::setValue(nts::Tristate value) {
        nts::Tristate result = value;
    }
}
