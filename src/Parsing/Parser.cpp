/*
/** EPITECH PROJECT, 2025
/** Parser.cpp
/** File description:
/** Don't forget to write a description ^^
*/

#include "../../include/Parsing/Parser.hpp"
#include "../../include/Parsing/ParsingException.hpp"

nts::Parser::Parser(const std::string &filename) : _filename(filename), _currentSection(ParsingSection::UNDEFINED) {}

nts::Parser::~Parser() {}

const std::vector<std::tuple<std::string, std::string>> nts::Parser::getChipsets() const
{
        return this->_chipsets;
}

const std::vector<std::tuple<std::string, std::string>> nts::Parser::getLinks() const
{
        return this->_links;
}

std::string cleanLine(std::string &line)
{
        if (line.length() == 0 || line[0] == '#')
        {
                return "";
        }
        for (int i = 0; i < line.length(); i++)
        {
                if (line.at(i) == '#')
                {
                        line.erase(i, 1);
                }
        }
        return line;
}

void nts::Parser::parseLine(const std::string &line)
{
        if (this->_currentSection == ParsingSection::UNDEFINED)
        {
                throw nts::ParsingException("Issue with file configuration"); 
        }
        std::stringstream ss(line);
        std::string s1;
        std::string s2;
        ss >> s1 >> s2;

        if (_currentSection == ParsingSection::CHIPSETS)
        {
                _chipsets.push_back(std::make_tuple(s1, s2));
        }
        else if (_currentSection == ParsingSection::LINKS)
        {
                _links.push_back(std::make_tuple(s1, s2));
        }
}

void nts::Parser::parse()
{
        std::ifstream file(this->_filename);

        if (!file.is_open())
        {
                throw nts::ParsingException("issue with the file opening");
        }

        std::string line;
        while (std::getline(file, line))
        {
                line = cleanLine(line);
                if (line.empty())
                        continue;
                if (line == ".chipsets:")
                {
                        this->_currentSection = ParsingSection::CHIPSETS;
                }
                else if (line == ".links:")
                {
                        this->_currentSection = ParsingSection::LINKS;
                }
                else
                {
                        parseLine(line);
                }
        }
}