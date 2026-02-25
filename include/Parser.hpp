/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Parser Header
*/

#ifndef NANO_1_PARSER_HPP
#define NANO_1_PARSER_HPP

#include <map>
#include <memory>
#include <string>  // <--- INDISPENSABLE POUR std::string
#include <set>     // <--- INDISPENSABLE POUR std::set
#include "IComponent.hpp"
#include "Factory.hpp"

namespace nts {
    class Parser {
        private:
            std::map<std::string, std::unique_ptr<nts::IComponent>> _components;
            nts::Factory _factory;
            std::set<std::string> _connectedPins; 
            std::string trimLine(const std::string &line);
            void parseChipset(const std::string &line);
            void parseLink(const std::string &line);
        public:
            Parser() = default;
            ~Parser() = default;
            void parse(const std::string &filename);
            std::map<std::string, std::unique_ptr<nts::IComponent>> getComponents();
    };
}

#endif // NANO_1_PARSER_HPP