//
// Created by crabe on 09/02/2026.
//

#include "../../../include/components/elementary_components/and.hpp"
#include "../../../include/Exception.hpp"

namespace nts {

    nts::Tristate And::compute(std::size_t pin)
    {
        if (pin < 1 || pin > 3)
            return nts::Undefined;

        if (pin == 1 || pin == 2) {
            if (_links[pin] == nullptr)
                throw Exception(std::string("Unlinked input pin on And: ") + std::to_string(pin));
            return _links[pin]->compute(_linkPins[pin]);
        }

        if (_links[1] == nullptr || _links[2] == nullptr)
            throw Exception("And gate missing input link");

        nts::Tristate a = _links[1]->compute(_linkPins[1]);
        nts::Tristate b = _links[2]->compute(_linkPins[2]);
        if (a == nts::False || b == nts::False)
            return nts::False;
        if (a == nts::Undefined || b == nts::Undefined)
            return nts::Undefined;
        return nts::True;
    }
} // nts

