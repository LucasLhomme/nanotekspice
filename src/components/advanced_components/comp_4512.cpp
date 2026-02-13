//
// Created by crabe on 12/02/2026.
//

#include "../../../include/components/advanced_components/comp_4512.hpp"

namespace nts {

    nts::Tristate Comp_4512::getVal(std::size_t p)
    {
        if (_links.find(p) == _links.end())
            return nts::Undefined;
        return _links[p].first->compute(_links[p].second);
    }

    nts::Tristate Comp_4512::compute(std::size_t pin)
    {
        if (pin != 14)
            return nts::Undefined;

        nts::Tristate oe = getVal(15); // Output Enable
        nts::Tristate inhibit = getVal(10); // forced zero
        nts::Tristate a = getVal(11); // input 1
        nts::Tristate b = getVal(12); // input 2
        nts::Tristate c = getVal(13); // input 3

        if (oe == nts::True)
            return nts::Undefined;
        if (inhibit == nts::True)
            return nts::False;
        if (oe == nts::Undefined || inhibit == nts::Undefined)
            return nts::Undefined;
        if (a == nts::Undefined || b == nts::Undefined || c == nts::Undefined)
            return nts::Undefined;
        const unsigned long index = (a == nts::True ? 1 : 0) +
                    (b == nts::True ? 2 : 0) +
                    (c == nts::True ? 4 : 0);
        // it's not a error if the 8 is missing.
        static const std::vector<std::size_t> dataPins = {1,2,3,4,5,6,7,9};
        if (index >= dataPins.size())
            return nts::Undefined;
        return getVal(dataPins[index]);
    }

} // nts