/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** main
*/

#include <iostream>
#include "../include/Shell.hpp"

/**
 * \brief Program entry point for the nanotekspice application.
 *
 * @param argc Argument count.
 * @param argv Argument vector (expects the .nts filename at argv[1]).
 * @return Exit code (0 on success, 84 on error).
 */
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
