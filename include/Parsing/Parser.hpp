/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Parser
*/

#ifndef _PARSER_HPP
#define _PARSER_HPP

#include <string>
#include <vector>
#include <tuple>
#include <fstream>
#include <exception>
#include <sstream>
#include <filesystem>

namespace nts
{
    enum class ParsingSection {
        UNDEFINED,
        CHIPSETS,
        LINKS
    };

    class Parser {
    private:
        std::string _filename;
        std::vector<std::tuple<std::string, std::string>> _chipsets;
        std::vector<std::tuple<std::string, std::string>> _links;
        ParsingSection _currentSection;

    public:
        Parser(const std::string &filename);
        ~Parser();

        void parse();
        void parseLine(const std::string &line);

        const std::vector<std::tuple<std::string, std::string>> getChipsets() const;
        const std::vector<std::tuple<std::string, std::string>> getLinks() const;
    };
}

#endif