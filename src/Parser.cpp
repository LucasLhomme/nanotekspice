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
#include <algorithm>
#include <cctype>
#include "../include/Exception.hpp"

namespace nts {

    std::string Parser::trimLine(const std::string &line)
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

    void Parser::parseChipset(const std::string &line)
    {
        std::stringstream ss(line);
        std::string type;
        std::string name;
        std::string extra;

        if (!(ss >> type >> name))
            throw ParserException("Incomplete chipset definition: " + line);
        if (ss >> extra)
            throw ParserException("Too many arguments in chipset definition: " + line);
        for (char c : name) {
            if (!std::isalnum(c) && c != '_')
                throw ParserException("Invalid character in component name: " + name);
        }
        if (_components.find(name) != _components.end())
            throw ParserException("Component name already exists: " + name);
        _components[name] = _factory.createComponent(type);
    }

    void Parser::parseLink(const std::string &line)
    {
        std::stringstream ss(line);
        std::string str_link_a;
        std::string str_link_b;
        std::string extra;

        if (!(ss >> str_link_a >> str_link_b))
            throw ParserException("Invalid link line format: " + line);
        if (ss >> extra)
            throw ParserException("Too many arguments in link definition: " + line);
        size_t pos_a = str_link_a.find(':');
        if (pos_a == std::string::npos)
            throw ParserException("Invalid link format (missing :) in: " + str_link_a);
        std::string name_a = str_link_a.substr(0, pos_a);
        std::string pin_str_a = str_link_a.substr(pos_a + 1);
        if (pin_str_a.empty() || !std::all_of(pin_str_a.begin(), pin_str_a.end(), ::isdigit))
            throw ParserException("Pin is not a valid number: " + pin_str_a);
            
        size_t pin_a;
        try {
            pin_a = std::stoul(pin_str_a);
        } catch (const std::exception &e) {
            throw ParserException("Invalid pin number in link: " + pin_str_a);
        }
        size_t pos_b = str_link_b.find(':');
        if (pos_b == std::string::npos)
            throw ParserException("Invalid link format (missing :) in: " + str_link_b);    
        std::string name_b = str_link_b.substr(0, pos_b);
        std::string pin_str_b = str_link_b.substr(pos_b + 1);
        if (pin_str_b.empty() || !std::all_of(pin_str_b.begin(), pin_str_b.end(), ::isdigit))
            throw ParserException("Pin is not a valid number: " + pin_str_b);
            
        size_t pin_b;
        try {
            pin_b = std::stoul(pin_str_b);
        } catch (const std::exception &e) {
            throw ParserException("Invalid pin number in link: " + pin_str_b);
        }
        if (_components.find(name_a) == _components.end() || _components.find(name_b) == _components.end())
            throw ParserException("Unknown component name in links");
        _connectedPins.insert(str_link_a);
        _connectedPins.insert(str_link_b);
        _components[name_a]->setLink(pin_a, *_components[name_b], pin_b);
        _components[name_b]->setLink(pin_b, *_components[name_a], pin_a);
    }

    void Parser::parse(const std::string &filename)
    {
        if (!filename.ends_with(".nts"))
            throw ParserException("filename not ending with .nts");      
        std::ifstream fs(filename);
        if (!fs.is_open())
            throw ParserException("Could not open file: " + filename);
        _connectedPins.clear();   
        std::string line;
        int state = 0;
        bool hasChipsets = false;
        bool hasLinks = false;

        while (std::getline(fs, line)) {
            line = trimLine(line);
            if (line.empty())
                continue;
            if (line == ".chipsets:") {
                state = 1;
                hasChipsets = true;
                continue;
            }
            if (line == ".links:") {
                state = 2;
                hasLinks = true;
                continue;
            }
            if (state == 1)
                parseChipset(line);
            else if (state == 2)
                parseLink(line);
            else
                throw ParserException("Instruction found outside of a section: " + line);
        }
        if (!hasChipsets)
            throw ParserException("Missing .chipsets section in file");
        if (!hasLinks)
            throw ParserException("Missing .links section in file");
        if (_components.empty())
            throw ParserException("No components declared in file");
    }

    std::map<std::string, std::unique_ptr<nts::IComponent>> Parser::getComponents()
    {
        return std::move(_components);
    }
}
