/*
** EPITECH PROJECT, 2026
** nano
** File description:
** IComponent
*/

#ifndef I_COMPONENT_HPP
#define I_COMPONENT_HPP

#include <iostream>
#include <string>
#include <map>
#include <memory>
#include <utility>

namespace nts {
    enum Tristate {
        Undefined = (-true),
        True = true,
        False = false,
    };

    class IComponent {
        public:
            virtual ~IComponent() = default;
            virtual void simulate(std::size_t tick) = 0;
            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
    };
}

namespace nts {
    inline nts::Tristate operator&&(nts::Tristate a, nts::Tristate b)
    {
        if (a == nts::Tristate::True && b == nts::Tristate::True) {
            return nts::Tristate::True;
        } else if (a == nts::Tristate::False || b == nts::Tristate::False) {
            return nts::Tristate::False;
        }
        return nts::Tristate::Undefined;
    }

    inline nts::Tristate operator||(nts::Tristate a, nts::Tristate b)
    {
        if (a == nts::Tristate::True && b == nts::Tristate::True) {
            return nts::Tristate::True;
        } else if (a == nts::Tristate::True || b == nts::Tristate::True) {
            return nts::Tristate::True;
        } else if (a == nts::Tristate::False && b == nts::Tristate::False) {
            return nts::Tristate::False;
        }
        return nts::Tristate::Undefined;
    }

    inline nts::Tristate operator^(nts::Tristate a, nts::Tristate b)
    {
        if (a == nts::Tristate::False && b == nts::Tristate::True) {
            return nts::Tristate::True;
        } else if (a == nts::Tristate::True && b == nts::Tristate::False) {
            return nts::Tristate::True;
        } else if (a == nts::Tristate::False && b == nts::Tristate::False) {
            return nts::Tristate::False;
        } else if (a == nts::Tristate::True && b == nts::Tristate::True) {
            return nts::Tristate::False;
        }
        return nts::Tristate::Undefined;
    }

    inline nts::Tristate operator!(nts::Tristate value)
    {
        if (value == nts::Tristate::True) {
            return nts::Tristate::False;
        } else if (value == nts::Tristate::False) {
            return nts::Tristate::True;
        }
        return nts::Tristate::Undefined;
    }
}

#endif