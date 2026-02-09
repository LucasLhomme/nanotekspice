/*
** EPITECH PROJECT, 2026
** nano
** File description:
** main
*/

#include "../include/IComponent.hpp"
#include "../include/Parser.hpp"

int main(int argc, char** argv)
{
    if (argc == 2) {
        std::string filename = argv[1];
        if (filename.ends_with(".nts")) {

        }
        else {
            std::cerr << "Usage: " << argv[0] << " filename" << std::endl;
            return 84;
        }
    }
    return 0;
}