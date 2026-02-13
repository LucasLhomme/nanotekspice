/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** GraphicComponent
*/

#ifndef GRAPHICCOMPONENT_HPP_
#define GRAPHICCOMPONENT_HPP_

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <map>
#include "../include/IComponent.hpp"

namespace nts {

    class GraphicComponent {
    public:
        GraphicComponent(const std::string &name, const sf::Vector2f &position, const sf::Font &font);
        
        void setPinState(std::size_t pinId, nts::Tristate state);
        void draw(sf::RenderWindow &window);
        sf::Vector2f getPinPosition(std::size_t pinId) const;
        const std::string& getName() const { return m_name; }
        sf::Vector2f getPosition() const { return m_position; }

    private:
        std::string m_name;
        sf::Vector2f m_position;
        sf::RectangleShape m_rect;
        sf::Text m_label;
        bool m_fontValid;

        struct Pin {
            std::size_t id;
            sf::CircleShape shape;
            sf::Text label;
            nts::Tristate state;
            bool isOutput;
        };
        
        std::map<std::size_t, Pin> m_pins;

        void createPins(const sf::Font &font);
        sf::Color getStateColor(nts::Tristate state);
    };

}

#endif
