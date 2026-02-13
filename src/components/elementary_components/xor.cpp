//
// Created by crabe on 09/02/2026.
//

#include "../../../include/components/elementary_components/xor.hpp"
#include "../../../include/Exception.hpp"

namespace nts {

    Xor::Xor() {}

    nts::Tristate Xor::compute(std::size_t pin)
    {
        if (pin < 1 || pin > 3)
            return nts::Undefined;

        if (pin == 1 || pin == 2) {
            if (_links.find(pin) == _links.end())
                throw Exception(std::string("Unlinked input pin on Xor: ") + std::to_string(pin));
            return computeSafe(_links[pin].first, _links[pin].second);
        }

        if (_links.find(1) == _links.end() || _links.find(2) == _links.end())
            throw Exception("Xor gate missing input link");

        const nts::Tristate a = computeSafe(_links[1].first, _links[1].second);
        const nts::Tristate b = computeSafe(_links[2].first, _links[2].second);
        if (a == nts::Undefined || b == nts::Undefined)
            return nts::Undefined;
        if (a == b)
            return nts::False;
        return nts::True;
    }
}

