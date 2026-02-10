/*
** EPITECH PROJECT, 2026
** ComponentFactory
** File description:
** ComponentFactory
*/
#include "Factory/ComponentFactory.hpp"
#include "Exception/FactoryException.hpp"

ComponentFactory::ComponentFactory()
{
    // // Special components
    // _create["input"] = [](){ return std::make_unique<Input>(); };
    // _create["output"] = [](){return std::make_unique<Output>(); };
    // _create["true"] = [](){return std::make_unique<True>(); };
    // _create["false"] = [](){return std::make_unique<False>(); };
    // _create["clock"] = [](){return std::make_unique<Clock>(); };

    // // Elementary components
    // _create["and"] = [](){ return std::make_unique<And>(); };
    // _create["or"] = [](){return std::make_unique<Or>(); };
    // _create["xor"] = [](){return std::make_unique<Xor>(); };
    // _create["not"] = [](){return std::make_unique<Not>(); };
}

std::unique_ptr<nts::IComponent> ComponentFactory::createComponent(const std::string &type)
{
    if (_create.find(type) == _create.end())
        throw nts::FactoryException("Unknown component type: '" + type + "', can't create it.");
    return _create[type]();
}
