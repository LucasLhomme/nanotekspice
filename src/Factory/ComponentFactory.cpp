/*
** EPITECH PROJECT, 2026
** ComponentFactory
** File description:
** ComponentFactory
*/
#include "Factory/ComponentFactory.hpp"
#include "../../include/Factory/FactoryException.hpp"
#include "Special-Components/InputComponent.hpp"
#include "Special-Components/TrueComponent.hpp"
#include "Special-Components/FalseComponent.hpp"
#include "Special-Components/ClockComponent.hpp"

nts::ComponentFactory::ComponentFactory()
{
    // // Special componentsnts
    // _create["input"] = [](){ return std::make_unique<Input>(); };
    // // _create["output"] = [](){return std::make_unique<Output>(); };
    // _create["true"] = [](){ return std::make_unique<class nts::True>(); };
    // _create["false"] = [](){ return std::make_unique<class nts::False>(); };
    // _create["clock"] = [](){ return std::make_unique<Clock>(); };
    // // Special components
    _create["input"] = [](){ return std::make_unique<nts::InputComponent>(); };
    // _create["output"] = [](){return std::make_unique<Output>(); };
    _create["true"] = [](){ return std::make_unique<nts::TrueComponent>(); };
    _create["false"] = [](){ return std::make_unique<nts::FalseComponent>(); };
    _create["clock"] = [](){ return std::make_unique<nts::ClockComponent>(); };
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createComponent(const std::string &type)
{
    if (_create.find(type) == _create.end())
        throw nts::FactoryException("Unknown component type: '" + type + "', can't create it.");
    return _create[type]();
}
