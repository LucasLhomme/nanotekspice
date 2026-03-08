//
// Created by crabe on 12/02/2026.
//

#include "../../../include/components/advanced_components/comp_4514.hpp"

namespace nts {

    /**
     * \brief Map 4-bit input to one-hot outputs for the 4514 decoder.
     *
     * @param pin Pin number to query.
     * @return True for the active output, False/Undefined otherwise.
     */
    nts::Tristate Comp_4514::compute(std::size_t pin)
    {
        nts::Tristate inhibit = getLinkValue(23);
        nts::Tristate input1 = getLinkValue(2);
        nts::Tristate input2 = getLinkValue(3);
        nts::Tristate input3 = getLinkValue(21);
        nts::Tristate input4 = getLinkValue(22);
        int index = 0;

        if (inhibit == nts::True)
            return nts::False;
        if (inhibit == nts::Undefined)
            return nts::Undefined;
        if (input1 == nts::Undefined || input2 == nts::Undefined ||
            input3 == nts::Undefined || input4 == nts::Undefined)
            return nts::Undefined;

        static const std::vector<std::size_t> outputs_maps = {
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
}