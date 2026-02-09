/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** IComponent
*/

#ifndef NANO_1_ICOMPONENT_HPP
#define NANO_1_ICOMPONENT_HPP

#include <cstddef>

namespace nts
{
	enum ComponentType {
        INPUT,
        OUTPUT,
        CLOCK,
        TRUE,
        FALSE,
        GATE,
        OTHER
    };

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
        virtual ComponentType getType() const = 0;
    };
}
#endif //NANO_1_ICOMPONENT_HPP