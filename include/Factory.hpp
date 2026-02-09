/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Factory
*/

#ifndef NANO_1_FACTORY_HPP
#define NANO_1_FACTORY_HPP

#include <memory>       // Pour std::unique_ptr
#include <string>       // Pour std::string
#include <map>          // Pour std::map
#include <functional>   // Pour std::function
#include <iostream>     // Pour les erreurs éventuelles
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