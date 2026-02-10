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
#include <bits/stdc++.h>

namespace nts {
    class Core {
        private:
            std::vector<nts::IComponent *> components;

        public:
            Core();
            ~Core();
    
            void core_loop();
    };
}

#endif
