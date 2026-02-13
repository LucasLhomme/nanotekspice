/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** main_gui
*/

#include <iostream>
#include "../include/Parser.hpp"
#include "../include/Circuit.hpp"
#include "GraphicInterface.hpp"

int main(int ac, char **av)
{
    if (ac < 2) {
        std::cerr << "Usage: ./nanotekspice_gui file.nts" << std::endl;
        return 84;
    }

    try {
        nts::Circuit circuit;
        nts::Parser parser;
        
        parser.parse(av[1]);
        circuit.setComponents(parser.getComponents());

        nts::GraphicInterface gui(circuit);
        gui.run();

        return 0;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 84;
    }
}
