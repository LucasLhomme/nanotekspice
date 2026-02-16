/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** comp_4013
*/

#ifndef COMP_4013_HPP_
#define COMP_4013_HPP_

#include "../AComponent.hpp"

namespace nts {
    class Comp_4013 : public AComponent {
        private:
            nts::Tristate _output1;
            nts::Tristate _noutput1;
            nts::Tristate _lastClock1;
            nts::Tristate _output2;
            nts::Tristate _noutput2;
            nts::Tristate _lastClock2;
            void updateFlipFlop(nts::Tristate data, nts::Tristate clock, nts::Tristate set, nts::Tristate reset, nts::Tristate &output, nts::Tristate &noutput, nts::Tristate &lastClock);
        public:
            Comp_4013();
            ~Comp_4013() override = default;
            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin) override;
    };
}

#endif