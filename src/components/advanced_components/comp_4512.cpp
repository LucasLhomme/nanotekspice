//
// Created by crabe on 12/02/2026.
//

#include "../../../include/components/advanced_components/comp_4512.hpp"

namespace nts {

    nts::Tristate Comp_4512::compute(std::size_t pin)
    {
        if (pin != 14)
            return nts::Undefined;

        nts::Tristate oe = getLinkValue(15);
        nts::Tristate inhibit = getLinkValue(10);
        nts::Tristate a = getLinkValue(11);
        nts::Tristate b = getLinkValue(12);
        nts::Tristate c = getLinkValue(13);

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
        static const std::vector<std::size_t> dataPins = {1,2,3,4,5,6,7,9};
        if (index >= dataPins.size())
            return nts::Undefined;
        return getLinkValue(dataPins[index]);
    }
}