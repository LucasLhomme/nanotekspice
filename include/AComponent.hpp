/*
** EPITECH PROJECT, 2026
** nts
** File description:
** Abstract class de IComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

#include "IComponent.hpp"

namespace nts {
    class AComponent : public IComponent {
        protected:
            nts::Tristate status;
            std::string type;
            std::string name;
            
        public:

            virtual ~AComponent() {};

            virtual nts::Tristate getStatus() const = 0;
            virtual std::string getType() const = 0;
            virtual std::string getName() const = 0;
    };
}

#endif /* !ACOMPONENT_HPP_ */
