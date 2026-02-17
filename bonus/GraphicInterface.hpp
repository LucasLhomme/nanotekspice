/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** GraphicInterface
*/

#ifndef GRAPHICINTERFACE_HPP_
#define GRAPHICINTERFACE_HPP_

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <map>
#include <string>
#include "../include/Circuit.hpp"
#include "GraphicComponent.hpp"

namespace nts {

    class GraphicInterface {
    public:
        GraphicInterface(Circuit &circuit);
        ~GraphicInterface() = default;

        void run();
        void captureSnapshot();
        void simulateAndCapture();

    private:
        Circuit &m_circuit;
        sf::RenderWindow m_window;
        sf::Font m_font;

        std::map<std::string, std::unique_ptr<GraphicComponent>> m_components;

        struct Snapshot {
            std::size_t tick;
            std::map<std::string, std::map<std::size_t, nts::Tristate>> states;
        };
        
        std::vector<Snapshot> m_history;
        std::size_t m_displayTick;
        std::size_t m_maxTick;

        sf::RectangleShape m_sliderBar;
        sf::CircleShape m_sliderKnob;
        sf::Text m_sliderText;
        bool m_isDraggingSlider;

        sf::RectangleShape m_simulateButton;
        sf::Text m_simulateText;

        void initLayout();
        void update();
        void draw();
        void drawWires();
        void updateDisplay();
        void handleSliderInput(const sf::Event &event);
        void handleMouseClick(const sf::Vector2i &mousePos);
    };

}

#endif /* !GRAPHICINTERFACE_HPP_ */
