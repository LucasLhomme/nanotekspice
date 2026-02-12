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
#include "components/Special/Logger.hpp"
#include "components/elementary_components/and.hpp"
#include "components/elementary_components/not.hpp"
#include "components/elementary_components/or.hpp"
#include "components/elementary_components/xor.hpp"
#include "components/gates_components/comp_4069.hpp"
#include "components/gates_components/comp_4071.hpp"
#include "components/gates_components/comp_4030.hpp"
#include "components/gates_components/comp_4001.hpp"
#include "components/gates_components/comp_4081.hpp"
#include "components/gates_components/comp_4011.hpp"

namespace nts {

    Factory::Factory()
    {
        _creators["input"]  = []() { return std::make_unique<Input>(); };
        _creators["output"] = []() { return std::make_unique<Output>(); };
        _creators["clock"] = []() { return std::make_unique<Clock>(); };
        _creators["true"] = []() { return std::make_unique<TrueComponent>(); };
		_creators["false"] = []() { return std::make_unique<FalseComponent>(); };
		_creators["logger"] = []() { return std::make_unique<Logger>(); };
        _creators["and"] = []() { return std::make_unique<And>(); };
        _creators["xor"] = []() { return std::make_unique<Xor>(); };
        _creators["or"] = []() { return std::make_unique<Or>(); };
        _creators["not"] = []() { return std::make_unique<Not>(); };
        _creators["4069"] = []() { return std::make_unique<Comp_4069>(); };
        _creators["4071"] = []() { return std::make_unique<Comp_4071>(); };
        _creators["4030"] = []() { return std::make_unique<Comp_4030>(); };
        _creators["4001"] = []() { return std::make_unique<Comp_4001>(); };
        _creators["4081"] = []() { return std::make_unique<Comp_4081>(); };
        _creators["4011"] = []() { return std::make_unique<Comp_4011>(); };
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