/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Logger Header
*/

#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include "AComponent.hpp"
#include <fstream>

namespace nts {
    class Logger : public AComponent {
        private:
            std::ofstream _file;
            nts::Tristate _previousClock;
            nts::Tristate getPinValue(std::size_t pin);
        public:
            Logger();
            ~Logger() override;
            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin) override;
    };
}

#endif /* !LOGGER_HPP_ */