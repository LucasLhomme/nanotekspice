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
#include <map>
#include <memory>

namespace nts {
    class Core {
        private:
            std::size_t _tick;
            std::map<std::string, std::pair<std::string, std::unique_ptr<nts::IComponent>>> _components;

        public:
            Core(std::size_t tick, std::map<std::string, std::pair<std::string, std::unique_ptr<nts::IComponent>>> components);
            
            void addComponent(std::string &name, std::string &type, std::unique_ptr<nts::IComponent> component);
            nts::IComponent *getComponent(const std::string &name);

            void core_loop();
            void simulate();
            void display() const;
            void setInput(const std::string &name, const std::string &value);
    };
}

#endif
