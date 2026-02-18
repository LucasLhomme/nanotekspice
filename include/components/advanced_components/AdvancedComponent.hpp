#ifndef NANO_1_ADVANCED_COMPONENT_HPP
#define NANO_1_ADVANCED_COMPONENT_HPP

#include "components/AComponent.hpp"

namespace nts {

class AdvancedComponent : public AComponent {
protected:
    nts::Tristate getVal(std::size_t pin) {
        if (_links.find(pin) == _links.end())
            return nts::Undefined;
        return _links[pin].first->compute(_links[pin].second);
    }
public:
    virtual ~AdvancedComponent() = default;
};

} // namespace nts

#endif // NANO_1_ADVANCED_COMPONENT_HPP
