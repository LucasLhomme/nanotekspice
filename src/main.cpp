/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** main
*/

#include <iostream>
#include <csignal>
#include "../include/Parser.hpp"
#include "../include/Exception.hpp"
#include "../include/Circuit.hpp"

bool g_loopRunning = false;

void signalHandler(int signum) {
    (void)signum;
    g_loopRunning = false;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: ./nanotekspice file.nts" << std::endl;
        return 84;
    }
    nts::Circuit circuit;
    nts::Parser parser;
    try {
        parser.parse(argv[1]);
        circuit.setComponents(parser.getComponents());
    } catch (const ParserException &e) {
        std::cerr << "Parser error: " << e.what() << std::endl;
        return 84;
    } catch (const FactoryException &e) {
        std::cerr << "Factory error: " << e.what() << std::endl;
        return 84;
    } catch (const ComponentException &e) {
        std::cerr << "Component error: " << e.what() << std::endl;
        return 84;
    } catch (const CircuitException &e) {
        std::cerr << "Circuit error: " << e.what() << std::endl;
        return 84;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 84;
    }
    std::cout << "> ";
    std::string input;
    while (std::getline(std::cin, input)) {
        if (input == "exit") {
            break;
        } else if (input == "display") {
            circuit.display();
        } else if (input == "simulate") {
            circuit.simulate();
        } else if (input == "loop") {
            std::cout << "Loop command requires signal handling." << std::endl;
        } else {
            size_t pos = input.find('=');
            if (pos != std::string::npos) {
                std::string name = input.substr(0, pos);
                std::string value = input.substr(pos + 1);
                circuit.setValue(name, value);
            } else {
                std::cout << "Unknown command." << std::endl;
            }
        }
        std::cout << "> ";
    }

    return 0;
}
