/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** comp_4040
*/

#ifndef NANO_1_COMP_4040_HPP
#define NANO_1_COMP_4040_HPP

#include "../AComponent.hpp"

namespace nts {
    class Comp_4040 : public AComponent {
	    private:
    	    int _counter;
        	nts::Tristate _prevClock;
    	public:
        	Comp_4040();
        	~Comp_4040() override = default;
        	void simulate(std::size_t tick) override;
        	nts::Tristate compute(std::size_t pin) override;
    };
}

#endif // NANO_1_COMP_4040_HPP