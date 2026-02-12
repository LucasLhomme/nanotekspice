/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Factory
*/

#ifndef NANO_1_FACTORY_HPP
#define NANO_1_FACTORY_HPP

#include <memory>
#include <string>
#include <map>
#include <functional>
#include <iostream>
#include "IComponent.hpp"

namespace nts {

    class Factory {
    	private:
    	    std::map<std::string, std::function<std::unique_ptr<nts::IComponent>()>> _creators;
    	public:
    	    Factory();
    	    ~Factory() = default;
    	    std::unique_ptr<nts::IComponent> createComponent(const std::string &type);
    };

}

#endif //NANO_1_FACTORY_HPP