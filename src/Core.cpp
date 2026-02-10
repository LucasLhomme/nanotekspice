/*
** EPITECH PROJECT, 2026
** nts
** File description:
** fiichier de core.hpp
*/

#include "../include/Core.hpp"

nts::Core::Core() {}

nts::Core::~Core() {}

void exit(int signal) {
        std::exit(signal);
}

void nts::Core::core_loop() {
        std::string line;
        std::cout << "> ";
        while (std::getline(std::cin, line)) {
                if (line == "exit" || std::signal(SIGINT, exit)) {
                        break;
                }
                else if (line == "display") {
                        
                }
        }
}