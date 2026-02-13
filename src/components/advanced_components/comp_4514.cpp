//
// Created by crabe on 12/02/2026.
//

#include "../../../include/components/advanced_components/comp_4514.hpp"

namespace nts {

    nts::Tristate Comp_4514::getVal(std::size_t p)
    {
        if (_links.find(p) == _links.end())
            return nts::Undefined;
        return _links[p].first->compute(_links[p].second);
    }

    nts::Tristate Comp_4514::compute(std::size_t pin)
    {
        nts::Tristate inhibit = getVal(23); // Forced Zero
        nts::Tristate input1 = getVal(2);
        nts::Tristate input2 = getVal(3);
        nts::Tristate input3 = getVal(21);
        nts::Tristate input4 = getVal(22);
        int index = 0;

        if (inhibit == nts::True)
            return nts::False;
        if (inhibit == nts::Undefined)
            return nts::Undefined;
        if (input1 == nts::Undefined || input2 == nts::Undefined ||
            input3 == nts::Undefined || input4 == nts::Undefined)
            return nts::Undefined;

        static const std::vector<std::size_t> outputs_maps = {
            //BE CAREFULL 11 is the 0 output door but on the spreadsheet it's like that. IT'S NOT a random number.
            11, 9, 10, 8, 7, 6, 5, 4, 18, 17, 20, 19, 14, 13, 16, 15
        };
        index = (input1 == nts::True ? 1 : 0) +
                          (input2 == nts::True ? 2 : 0) +
                          (input3 == nts::True ? 4 : 0) +
                          (input4 == nts::True ? 8 : 0);
        if (outputs_maps[index] == pin)
            return nts::True;
        return nts::False;
    }

} // nts