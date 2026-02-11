/*
** EPITECH PROJECT, 2026
** Core
** File description:
** The loop for the command interpretor
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <vector>
#include "IComponent.hpp"
#include <algorithm>
#include <csignal>


namespace nts {
    class Core {
        private:
            std::vector<nts::IComponent *> components;
            std::vector<std::tuple<std::string, std::string>> components_info;
            std::size_t tick;

        public:
            Core(std::vector<std::tuple<std::string, std::string>> components_inf);
            ~Core();
    
            void core_loop();
            void display();
            void simulate();

            std::size_t getTick() const;
    };
}

#endif
