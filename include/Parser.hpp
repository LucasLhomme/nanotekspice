/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Parser Header
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <string>
#include <vector>
#include <memory>
#include <map>
#include "IComponent.hpp"
#include "Factory.hpp"

namespace nts {
    class Parser {
        private:
            nts::Factory _factory;
            std::map<std::string, std::unique_ptr<nts::IComponent>> _components;
            void parseChipset(const std::string &line);
            void parseLink(const std::string &line);
            std::string trimLine(const std::string &line);
        public:
            Parser() = default;
            ~Parser() = default;
            void parse(const std::string &filename);
			std::map<std::string, std::unique_ptr<nts::IComponent>> getComponents();
    };
}

#endif