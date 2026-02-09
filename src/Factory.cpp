/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Factory implementation
*/

#include "../include/Factory.hpp"
#include "../include/components/Input.hpp"
#include "../include/components/Output.hpp"
#include "../include/components/Clock.hpp"
#include "../include/Exception.hpp"

namespace nts {

    Factory::Factory()
    {
        _creators["input"]  = []() { return std::make_unique<Input>(); };
        _creators["output"] = []() { return std::make_unique<Output>(); };
        _creators["clock"] = []() { return std::make_unique<Clock>(); };
    }

    std::unique_ptr<nts::IComponent> Factory::createComponent(const std::string &type)
    {
        auto component = _creators.find(type);

        if (component == _creators.end()) {
            throw Exception("Unknown component type: " + type);
        }
        return component->second();
    }
}