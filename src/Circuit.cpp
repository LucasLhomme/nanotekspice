/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Circuit Implementation
*/

#include "Circuit.hpp"
#include "components/Special/Input.hpp"
#include "components/Special/Output.hpp"
#include "components/Special/Clock.hpp"
#include "components/Special/True.hpp"
#include "components/Special/False.hpp"

namespace nts {

    static std::string tristateToString(nts::Tristate v) {
        if (v == nts::True)
			return "1";
        if (v == nts::False)
			return "0";
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
        if (dynamic_cast<nts::Input*>(comp.get()) || 
            dynamic_cast<nts::Clock*>(comp.get()) ||
            dynamic_cast<nts::TrueComponent*>(comp.get()) ||
            dynamic_cast<nts::FalseComponent*>(comp.get())) {
            std::cout << "  " << name << ": " << tristateToString(comp->compute(1)) << std::endl;
        }
    }
        std::cout << "output(s):" << std::endl;
        for (auto const& [name, comp] : _components) {
            if (dynamic_cast<nts::Output*>(comp.get()))
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
        nts::Input *inputPtr = dynamic_cast<nts::Input*>(it->second.get());
        nts::Clock *clockPtr = dynamic_cast<nts::Clock*>(it->second.get());
        if (!inputPtr && !clockPtr) {
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
        if (inputPtr)
            inputPtr->setValue(newState);
        else if (clockPtr)
            clockPtr->setValue(newState);
    }
}