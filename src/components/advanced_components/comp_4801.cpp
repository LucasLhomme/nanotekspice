//
// Created by crabe on 13/02/2026.
//

#include "../../../include/components/advanced_components/comp_4801.hpp"
#include "../../../include/IComponent.hpp"

namespace nts {

    nts::Tristate Comp_4801::getVal(std::size_t p)
    {
        if (_links.find(p) == _links.end())
            return nts::Undefined;
        return _links[p].first->compute(_links[p].second);
    }

    nts::Tristate Comp_4801::compute(std::size_t)
    {
        return Tristate::Undefined;
    }
} // nts