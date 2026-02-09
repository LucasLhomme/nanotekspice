/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Circuit Implementation
*/

#include "../include/Circuit.hpp"
#include "../include/components/Input.hpp"
#include "../include/components/Clock.hpp"

namespace nts {

    static std::string tristateToString(nts::Tristate v) {
        if (v == nts::True) return "1";
        if (v == nts::False) return "0";
        return "U";
    }

    Circuit::Circuit() : _tick(0){}

    void Circuit::setComponents(std::map<std::string, std::unique_ptr<nts::IComponent>> components)
    {
        _components = std::move(components);
    }

    void Circuit::simulate()
    {
        _tick++;
        for (auto &it : _components) {
            it.second->simulate(_tick);
        }
    }

    void Circuit::display()
    {
        std::cout << "tick: " << _tick << std::endl;
        std::cout << "input(s):" << std::endl;
        for (auto const& [name, comp] : _components) {
            if (comp->getType() == nts::ComponentType::INPUT ||
                comp->getType() == nts::ComponentType::CLOCK) {
                std::cout << "  " << name << ": " << tristateToString(comp->compute(1)) << std::endl;
            }
        }

        std::cout << "output(s):" << std::endl;
        for (auto const& [name, comp] : _components) {
            if (comp->getType() == nts::ComponentType::OUTPUT)
                std::cout << "  " << name << ": " << tristateToString(comp->compute(1)) << std::endl;
        }
    }

    void Circuit::setValue(const std::string &inputName, const std::string &value)
    {
        auto it = _components.find(inputName);
        if (it == _components.end()) {
            std::cerr << "Error: Component '" << inputName << "' not found." << std::endl;
            return;
        }

        nts::ComponentType type = it->second->getType();
        if (type != nts::ComponentType::INPUT && type != nts::ComponentType::CLOCK) {
            std::cerr << "Error: '" << inputName << "' is not an input or clock." << std::endl;
            return;
        }

        nts::Tristate newState;
        if (value == "1")
            newState = nts::True;
        else if (value == "0")
            newState = nts::False;
        else if (value == "U")
            newState = nts::Undefined;
        else {
            std::cerr << "Error: Invalid value '" << value << "'. Use 0, 1 or U." << std::endl;
            return;
        }
        if (type == nts::ComponentType::INPUT) {
            auto *inputParams = static_cast<nts::Input*>(it->second.get());
            inputParams->setValue(newState);
        } else if (type == nts::ComponentType::CLOCK) {
             auto *clockParams = static_cast<nts::Clock*>(it->second.get());
             clockParams->setValue(newState);
        }
    }
}