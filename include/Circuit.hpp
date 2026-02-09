/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include <map>
#include <string>
#include <memory>
#include <iostream>
#include <vector>
#include "IComponent.hpp"

namespace nts {
    class Circuit {
	    private:
    	    std::map<std::string, std::unique_ptr<nts::IComponent>> _components;
        	std::size_t _tick;
	    public:
    	    Circuit();
        	~Circuit() = default;
        	void setComponents(std::map<std::string, std::unique_ptr<nts::IComponent>> components);
        	void simulate();
        	void display();
        	void setValue(const std::string &inputName, const std::string &value);
    };
}

#endif /* !CIRCUIT_HPP_ */