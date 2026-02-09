/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Parser Implementation
*/

#include "../include/Parser.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

std::string nts::Parser::trimLine(const std::string &line)
{
    std::string clean = line;
    size_t commentPos = clean.find('#');
    if (commentPos != std::string::npos)
        clean = clean.substr(0, commentPos);
    size_t end = clean.find_last_not_of(" \t");
    if (end == std::string::npos)
        return "";
    clean = clean.substr(0, end + 1);
    size_t start = clean.find_first_not_of(" \t");
    if (start != std::string::npos)
        clean = clean.substr(start);
    return clean;
}

void nts::Parser::parseChipset(const std::string &line)
{
    std::stringstream ss(line);
    std::string type;
    std::string name;
    std::string extra;

	if (!(ss >> type >> name))
    	throw std::invalid_argument("Incomplete chipset definition: " + line);
    if (ss >> extra)
        throw std::invalid_argument("Too many arguments in chipset definition: " + line);
    if (_components.find(name) != _components.end())
        throw std::invalid_argument("Component name already exists: " + name);
    _components[name] = _factory.createComponent(type);
}

void nts::Parser::parseLink(const std::string &line)
{
    std::stringstream ss(line);
    std::string str_link_a;
    std::string str_link_b;
    std::string extra;

    if (!(ss >> str_link_a >> str_link_b))
        throw std::invalid_argument("Invalid link line format: " + line);
    if (ss >> extra)
        throw std::invalid_argument("Too many arguments in link definition: " + line);

    size_t pos_a = str_link_a.find(':');
    if (pos_a == std::string::npos)
        throw std::invalid_argument("Invalid link format (missing :) in: " + str_link_a);
    std::string name_a = str_link_a.substr(0, pos_a);
    std::string pin_str_a = str_link_a.substr(pos_a + 1);
    size_t pin_a = std::stoul(pin_str_a);

    size_t pos_b = str_link_b.find(':');
    if (pos_b == std::string::npos)
        throw std::invalid_argument("Invalid link format (missing :) in: " + str_link_b);
    std::string name_b = str_link_b.substr(0, pos_b);
    std::string pin_str_b = str_link_b.substr(pos_b + 1);
    size_t pin_b = std::stoul(pin_str_b);

    if (_components.find(name_a) == _components.end() || _components.find(name_b) == _components.end())
        throw std::runtime_error("Unknown component name in links");
    _components[name_a]->setLink(pin_a, *_components[name_b], pin_b);
    _components[name_b]->setLink(pin_b, *_components[name_a], pin_a);
}

void nts::Parser::parse(const std::string &filename)
{
    std::ifstream fs(filename);
    if (!fs.is_open())
        throw std::runtime_error("Could not open file: " + filename);
    std::string line;
    int state = 0;
    while (std::getline(fs, line)) {
        line = trimLine(line);
        if (line.empty())
			continue;
        if (line == ".chipsets:") {
            state = 1;
            continue;
        }
        if (line == ".links:") {
            state = 2;
            continue;
        }
        if (state == 1) {
            parseChipset(line);
        } else if (state == 2) {
            parseLink(line);
        } else {
            throw std::invalid_argument("Instruction found outside of a section: " + line);
        }
    }
}

std::map<std::string, std::unique_ptr<nts::IComponent>> nts::Parser::getComponents()
{
    return std::move(_components);
}
