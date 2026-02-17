/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** IComponent
*/

#ifndef NANO_1_ICOMPONENT_HPP
#define NANO_1_ICOMPONENT_HPP

#include <cstddef>

namespace nts {
    enum Tristate {
        Undefined = (-true),
        True = true,
        False = false
    };

    class IComponent
    {
        public :
            virtual ~ IComponent () = default ;
            virtual void simulate(std::size_t tick) = 0;
            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
    };
}

namespace nts {
    inline nts::Tristate operator&&(nts::Tristate a, nts::Tristate b) {
        if (a == nts::False || b == nts::False)
            return nts::False;
        if (a == nts::True && b == nts::True)
            return nts::True;
        return nts::Undefined;
    }

    inline nts::Tristate operator||(nts::Tristate a, nts::Tristate b) {
        if (a == nts::True || b == nts::True)
            return nts::True;
        if (a == nts::False && b == nts::False)
            return nts::False;
        return nts::Undefined;
    }

    inline nts::Tristate operator^(nts::Tristate a, nts::Tristate b) {
        if (a == nts::Undefined || b == nts::Undefined)
            return nts::Undefined;
        if (a == b)
            return nts::False;
        return nts::True;
    }

    inline nts::Tristate operator!(nts::Tristate a) {
        if (a == nts::True)
            return nts::False;
        if (a == nts::False)
            return nts::True;
        return nts::Undefined;
    }
}

#endif //NANO_1_ICOMPONENT_HPP