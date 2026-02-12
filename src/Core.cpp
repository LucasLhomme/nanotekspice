/*
** EPITECH PROJECT, 2026
** nts
** File description:
** fiichier de core.hpp
*/

#include "../include/Core.hpp"

nts::Core::Core(std::map<std::string, std::pair<std::string, std::unique_ptr<nts::IComponent>>> &&components) : _components(std::move(components)) {}

nts::Core::~Core() {}

void signalHandler(int signal) {
        std::exit(signal);
}

void nts::Core::core_loop() {
    std::string line;
    std::cout << "> ";
    std::signal(SIGINT, signalHandler);

    while (std::getline(std::cin, line)) {
        if (line == "exit") {
            break;
        } else if (line == "display") {
           this->display();
        } else if (line == "simulate") {
            // this->simulate();
        } else {
            // input=value
        }
        std::cout << "> ";
    }
}

std::string tristateToString(nts::Tristate v) {
    if (v == nts::True)
        return "1";
    if (v == nts::False)
        return "0";
    return "U";
}

nts::IComponent *nts::Core::getComponent(const std::string &name) {
    auto comp = _components.find(name);

    if (comp == _components.end())
        return nullptr;

    return comp->second.second.get();
}

void nts::Core::addComponent(const std::string &name, std::string &type, std::unique_ptr<nts::IComponent> component) {

    _components[name] = std::make_pair(type, std::move(component));
}

int whichType(const std::pair<std::string, std::unique_ptr<nts::IComponent>> &_component)
{
    if (_component.first == "input" || _component.first == "clock") {
        return 1;
    }
    else if (_component.first == "output") {
        return 2;
    }
    else {
        return 3;
    }
}

void nts::Core::display() const {
    std::cout << "tick: " << _tick << std::endl;
    
    std::cout << "input(s):" << std::endl;
    for (const auto &pair : _components) {
        if (whichType(pair.second) == 1) {
            std::cout << "  " << pair.first << ": " << tristateToString(pair.second.second->compute(1)) << std::endl;
        }
    }
    
    std::cout << "output(s):" << std::endl;
    for (const auto &pair : _components) {
        if (whichType(pair.second) == 2) {
            std::cout << "  " << pair.first << ": " << tristateToString(pair.second.second->compute(1)) << std::endl;
        }
    }
}

void nts::Core::simulate() {
    _tick++;
    for (auto &pair : _components) {
        pair.second.second->simulate(_tick);
    }
}