//
// Created by crabe on 09/02/2026.
//

#include "../../../include/components/elementary_components/and.hpp"
#include "../../../include/Exception.hpp"

namespace nts {

    And::And() {}

    nts::Tristate And::compute(std::size_t pin)
    {
        if (pin < 1 || pin > 3)
            return nts::Undefined;

        if (pin == 1 || pin == 2) {
            if (_links.find(pin) == _links.end())
                throw Exception(std::string("Unlinked input pin on And: ") + std::to_string(pin));
            return computeSafe(_links[pin].first, _links[pin].second);
        }

        if (_links.find(1) == _links.end() || _links.find(2) == _links.end())
            throw Exception("And gate missing input link");

        nts::Tristate a = computeSafe(_links[1].first, _links[1].second);
        nts::Tristate b = computeSafe(_links[2].first, _links[2].second);
        if (a == nts::False || b == nts::False)
            return nts::False;
        if (a == nts::Undefined || b == nts::Undefined)
            return nts::Undefined;
        return nts::True;
    }
} // nts

