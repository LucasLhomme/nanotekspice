/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Factory implementation
*/

#include "Factory.hpp"
#include "components/Special/Input.hpp"
#include "components/Special/Output.hpp"
#include "components/Special/Clock.hpp"
#include "components/Special/True.hpp"
#include "components/Special/False.hpp"

namespace nts {

    Factory::Factory()
    {
        _creators["input"]  = []() { return std::make_unique<Input>(); };
        _creators["output"] = []() { return std::make_unique<Output>(); };
        _creators["clock"] = []() { return std::make_unique<Clock>(); };
        _creators["true"] = []() { return std::make_unique<class True>(); };
		_creators["false"] = []() { return std::make_unique<class False>(); };
    }

    std::unique_ptr<nts::IComponent> Factory::createComponent(const std::string &type)
    {
        auto component = _creators.find(type);

        if (component == _creators.end()) {
            throw std::runtime_error("Unknown component type: " + type);
        }
        return component->second();
    }
}