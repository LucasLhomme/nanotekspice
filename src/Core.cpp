/*
** EPITECH PROJECT, 2026
** nts
** File description:
** fiichier de core.hpp
*/

#include "../include/Core.hpp"

nts::Core::Core(std::vector<std::tuple<std::string, std::string>> component_inf) : components_info(component_inf) {}

nts::Core::~Core() {}

void exit(int signal) {
        std::exit(signal);
}

void nts::Core::core_loop() {
    std::string line;
    std::cout << "> ";
    std::signal(SIGINT, exit);

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

// bool compareComponents(nts::IComponent* a, nts::IComponent* b) {
//     return a->getName() < b->getName();
// }

std::string tristateToString(nts::Tristate v) {
    if (v == nts::True)
        return "1";
    if (v == nts::False)
        return "0";
    return "U";
}

void nts::Core::display() {
    std::cout << "tick: " << this->tick << std::endl;

    std::vector<nts::IComponent*> inputs;
    std::vector<nts::IComponent*> outputs;

    for (auto component : this->components) {
        if (component->getType() == "input" || component->getType() == "clock") {
            inputs.push_back(component);
        } else if (component->getType() == "output") {
            outputs.push_back(component);
        }
    }

    std::sort(inputs.begin(), inputs.end(), compareComponents);
    std::sort(outputs.begin(), outputs.end(), compareComponents);

    std::cout << "input(s):" << std::endl;
    for (auto in : inputs) {
        std::cout << "  " << in->getName() << ": " << get_status(*in) << std::endl;
    }

    std::cout << "output(s):" << std::endl;
    for (auto out : outputs) {
        out->compute()
        std::cout << "  " << out->getName() << ": " << get_status(*out) << std::endl;
    }
}

void nts::Core::simulate() {
    this->tick++;
    for (auto component : this->components) {
        component->simulate(tick);
    }
}