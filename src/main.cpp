/*
** EPITECH PROJECT, 2026
** nano
** File description:
** main
*/

#include "../include/IComponent.hpp"
#include "../include/Parsing/Parser.hpp"
#include "../include/Parsing/ParsingException.hpp"
#include "../include/Core.hpp"

int main(int argc, char **argv)
{
    // Parsing gestion arguments
    try
    {
        if (argc == 2)
        {
            std::string filename = argv[1];
            std::filesystem::path filepath = filename;

            if (filepath.extension() != ".nts")
            {
                throw nts::ParsingException("bah mauvaise interface");
            }
            else
            {
                nts::Parser p(filename);
                p.parse();
                nts::Core c;
                c.core_loop();
            }
        }
    }
    catch (const std::exception &e) {
        std::cerr << "Error : " << e.what() << std::endl;
        return 84;
    }
    return 0;
}