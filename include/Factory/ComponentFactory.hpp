/*
** EPITECH PROJECT, 2026
** nano
** File description:
** Factory
*/

#ifndef NANO_FACTORY_HPP
    #define NANO_FACTORY_HPP

#include <memory>
#include <unordered_map>
#include <functional>
#include <stdexcept>
#include "IComponent.hpp"

class ComponentFactory {
public:
    ComponentFactory();
    std::unique_ptr<nts::IComponent> createComponent(const std::string &type);

private:
    std::unordered_map<std::string, std::function<std::unique_ptr<nts::IComponent>()>> _create;
};

#endif //NANO_FACTORY_HPP
