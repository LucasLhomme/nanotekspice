/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Shell Implementation
*/

#include "../include/Shell.hpp"
#include "../include/Parser.hpp"
#include "../include/Exception.hpp"
#include <iostream>
#include <csignal>

volatile std::sig_atomic_t g_loopRunning = false;

/**
 * \brief Signal handler used to stop the loop mode on SIGINT.
 *
 * @param signum Signal number (ignored).
 */
static void signalHandler(int signum) {
    (void)signum;
    g_loopRunning = false;
}

namespace nts {
    /**
     * \brief Initialize the shell by parsing the .nts file and building the circuit.
     *
     * @param filename Path to the .nts file to load.
     * @return 0 on success, 84 on error.
     */
    int Shell::init(const std::string &filename) {
        nts::Parser parser;
        try {
            parser.parse(filename);
            _circuit.setComponents(parser.getComponents());
            return 0;
        } catch (const ParserException &e) {
            std::cerr << "Parser error: " << e.what() << std::endl;
        } catch (const FactoryException &e) {
            std::cerr << "Factory error: " << e.what() << std::endl;
        } catch (const ComponentException &e) {
            std::cerr << "Component error: " << e.what() << std::endl;
        } catch (const CircuitException &e) {
            std::cerr << "Circuit error: " << e.what() << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        return 84;
    }

    /**
     * \brief Handle a single shell command (display, simulate, loop, set value).
     *
     * @param input Command string entered by the user.
     */
    void Shell::handleCommand(const std::string &input) {
        if (input == "display")
            _circuit.display();
        else if (input == "simulate")
            _circuit.simulate();
        else if (input == "loop") {
            g_loopRunning = true;
            std::signal(SIGINT, signalHandler); 
            while (g_loopRunning) {
                _circuit.simulate();
                _circuit.display();
            }
            std::signal(SIGINT, SIG_DFL); 
        } else {
            size_t pos = input.find('=');
            if (pos != std::string::npos) {
                std::string name = input.substr(0, pos);
                std::string value = input.substr(pos + 1);
                _circuit.setValue(name, value);
            } else
                std::cout << "Unknown command." << std::endl;
        }
    }

    /**
     * \brief Run the interactive shell loop, reading commands from stdin.
     */
    void Shell::run() {
        std::string input;
        std::cout << "> ";
        while (std::getline(std::cin, input)) {
            if (input == "exit")
                break;
            handleCommand(input);
            std::cout << "> ";
        }
    }
}