/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Shell Header
*/

#ifndef NANO_1_SHELL_HPP
#define NANO_1_SHELL_HPP

#include <string>
#include "Circuit.hpp"

namespace nts {
    class Shell {
        private:
            nts::Circuit _circuit;
            void handleCommand(const std::string &input);
        public:
            Shell() = default;
            ~Shell() = default;
            int init(const std::string &filename);
            void run();
    };
}

#endif // NANO_1_SHELL_HPP