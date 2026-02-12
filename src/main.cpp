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
#include "../include/Factory/ComponentFactory.hpp"

void debugPrintMap(const std::map<std::string, std::pair<std::string, std::unique_ptr<nts::IComponent>>> &map) 
{
    std::cout << "========= DEBUG MAP CONTENT =========" << std::endl;
    std::cout << "Size: " << map.size() << " element(s)" << std::endl;

    if (map.empty()) {
        std::cout << "(Map is empty)" << std::endl;
        std::cout << "=====================================" << std::endl;
        return;
    }

    int index = 0;
    // Utilisation d'itérateurs classiques (compatible C++11/14/17)
    for (const auto &entry : map) {
        // entry.first  => La clé (std::string) : le Nom
        // entry.second => La valeur (std::pair)
        
        const std::string &name = entry.first;
        const std::string &type = entry.second.first;
        nts::IComponent *ptr = entry.second.second.get(); // On récupère le pointeur brut pour l'afficher

        std::cout << "[" << index << "] Key: '" << name << "'"
                  << " \t| Type: '" << type << "'"
                  << " \t| Ptr Address: " << ptr;
        
        if (ptr == nullptr) {
            std::cout << " (WARNING: NULL)";
        }
        std::cout << std::endl;
        
        index++;
    }
    std::cout << "=====================================" << std::endl;
}

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
                nts::ComponentFactory factory;
                std::map<std::string, std::pair<std::string, std::unique_ptr<nts::IComponent>>> component_tab;
                
                std::vector<std::tuple<std::string, std::string>> chipsets = p.getChipsets();
                std::vector<std::tuple<std::string, std::string>> links = p.getLinks();
                int test = 0;
                for (auto chipset : chipsets) {
                    std::unique_ptr<nts::IComponent> component = factory.createComponent(std::get<0>(chipset));
                    component_tab[std::get<1>(chipset)] = std::make_pair(std::get<0>(chipset), std::move(component));
                }
                debugPrintMap(component_tab);
                nts::Core c(std::move(component_tab));
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