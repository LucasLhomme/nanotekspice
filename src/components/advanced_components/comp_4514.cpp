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
     return nts::Undefined;
    }

} // nts