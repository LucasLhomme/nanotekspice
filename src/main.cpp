/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** main
*/

#include <iostream>
#include "../include/Shell.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: ./nanotekspice file.nts" << std::endl;
        return 84;
    }
    nts::Shell shell;
    if (shell.init(argv[1]) == 84)
        return 84;
    shell.run();
    return 0;
}
