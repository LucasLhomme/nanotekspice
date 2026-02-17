/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** GraphicInterface implementation
*/

#define private public
#define protected public
#include "../include/Circuit.hpp"
#include "../include/components/AComponent.hpp"
#undef protected
#undef private

#include "../include/components/Special/Input.hpp"
#include "../include/components/Special/Clock.hpp"
#include "GraphicInterface.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>

namespace nts {

    GraphicInterface::GraphicInterface(Circuit &circuit)
        : m_circuit(circuit), m_displayTick(0), m_maxTick(0), m_isDraggingSlider(false)
    {
        m_window.create(sf::VideoMode(1400, 900), "NanoTekSpice GUI - Time Machine");
        m_window.setFramerateLimit(60);

        if (!m_font.loadFromFile("/usr/share/fonts/Adwaita/AdwaitaMono-Regular.ttf")) {
            if (!m_font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf")) {
                std::cerr << "Warning: Could not load font" << std::endl;
            }
        }

        m_sliderBar.setSize(sf::Vector2f(300.f, 8.f));
        m_sliderBar.setFillColor(sf::Color(100, 100, 100));
        m_sliderBar.setPosition(30.f, 20.f);

        m_sliderKnob.setRadius(8.f);
        m_sliderKnob.setOrigin(8.f, 8.f);
        m_sliderKnob.setFillColor(sf::Color::White);
        m_sliderKnob.setPosition(30.f, 24.f);

        m_sliderText.setFont(m_font);
        m_sliderText.setCharacterSize(14);
        m_sliderText.setFillColor(sf::Color::White);
        m_sliderText.setPosition(350.f, 10.f);
        m_sliderText.setString("Tick: 0/0  [SPC]=Step  [L/R]=Seek");

        // Simulate Button
        m_simulateButton.setSize(sf::Vector2f(100.f, 30.f));
        m_simulateButton.setFillColor(sf::Color(70, 70, 80));
        m_simulateButton.setOutlineThickness(2.f);
        m_simulateButton.setOutlineColor(sf::Color::White);
        m_simulateButton.setPosition(700.f, 10.f);

        m_simulateText.setFont(m_font);
        m_simulateText.setString("SIMULATE");
        m_simulateText.setCharacterSize(14);
        m_simulateText.setFillColor(sf::Color::White);
        sf::FloatRect textBounds = m_simulateText.getLocalBounds();
        m_simulateText.setPosition(
            700.f + (100.f - textBounds.width) / 2.f,
            10.f + (30.f - textBounds.height) / 2.f - 2.f
        );

        initLayout();
        captureSnapshot();
    }

    void GraphicInterface::initLayout()
    {
        const auto &components = m_circuit._components;
        
        int col = 0;
        int row = 0;
        const int maxCols = 5;
        float startX = 50.f;
        float startY = 100.f;
        float spacingX = 250.f;
        float spacingY = 200.f;

        for (const auto &[name, componentPtr] : components) {
            sf::Vector2f pos(startX + col * spacingX, startY + row * spacingY);
            m_components[name] = std::make_unique<GraphicComponent>(name, pos, m_font);
            
            col++;
            if (col >= maxCols) {
                col = 0;
                row++;
            }
        }
    }

    void GraphicInterface::captureSnapshot()
    {
        Snapshot snap;
        snap.tick = m_history.size();

        const auto &components = m_circuit._components;
        for (const auto &[name, componentPtr] : components) {
            std::map<std::size_t, nts::Tristate> pinStates;
            
            for (std::size_t i = 1; i <= 14; ++i) {
                try {
                    pinStates[i] = componentPtr->compute(i);
                } catch (...) {
                    pinStates[i] = nts::Undefined;
                }
            }
            snap.states[name] = pinStates;
        }

        m_history.push_back(snap);
        m_maxTick = snap.tick;
        if (m_displayTick == m_maxTick - 1) {
            m_displayTick = m_maxTick;
        }
    }

    void GraphicInterface::simulateAndCapture()
    {
        m_circuit.simulate();
        captureSnapshot();
    }

    void GraphicInterface::updateDisplay()
    {
        if (m_displayTick >= m_history.size()) {
            return;
        }

        const auto &snap = m_history[m_displayTick];
        for (auto &[name, component] : m_components) {
            auto it = snap.states.find(name);
            if (it != snap.states.end()) {
                for (const auto &[pinId, state] : it->second) {
                    component->setPinState(pinId, state);
                }
            }
        }
    }

    void GraphicInterface::handleSliderInput(const sf::Event &event)
    {
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mousePos = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
            if (m_sliderKnob.getGlobalBounds().contains(mousePos) || m_sliderBar.getGlobalBounds().contains(mousePos)) {
                m_isDraggingSlider = true;
            }
        }
        if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
            m_isDraggingSlider = false;
        }
    }

    void GraphicInterface::update()
    {
        if (m_isDraggingSlider && m_maxTick > 0) {
            sf::Vector2f mousePos = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
            float x = std::clamp(mousePos.x, 30.f, 330.f);
            float ratio = (x - 30.f) / 300.f;
            m_displayTick = static_cast<std::size_t>(std::round(ratio * m_maxTick));
            m_sliderKnob.setPosition(30.f + ratio * 300.f, 24.f);
        }

        m_sliderText.setString("Tick: " + std::to_string(m_displayTick) + "/" + std::to_string(m_maxTick) + "  [SPC]=Step  [L/R]=Seek");
        updateDisplay();
    }

    void GraphicInterface::drawWires()
    {
        if (m_displayTick >= m_history.size()) {
            return;
        }

        const auto &circuitComps = m_circuit._components;
        for (const auto &[sourceName, componentPtr] : circuitComps) {
            auto *srcComponent = dynamic_cast<const nts::AComponent*>(componentPtr.get());
            if (!srcComponent) continue;

            for (const auto &[pinId, link] : srcComponent->_links) {
                const nts::IComponent* targetPtr = link.first;
                std::size_t targetPinId = link.second;

                std::string targetName;
                for (const auto &[name, comp] : circuitComps) {
                    if (comp.get() == targetPtr) {
                        targetName = name;
                        break;
                    }
                }

                if (targetName.empty()) continue;

                auto srcIt = m_components.find(sourceName);
                auto tgtIt = m_components.find(targetName);
                if (srcIt == m_components.end() || tgtIt == m_components.end()) continue;

                sf::Vector2f start = srcIt->second->getPinPosition(pinId);
                sf::Vector2f end = tgtIt->second->getPinPosition(targetPinId);

                sf::Vertex line[] = {
                    sf::Vertex(start, sf::Color::Cyan),
                    sf::Vertex(end, sf::Color::Cyan)
                };
                m_window.draw(line, 2, sf::Lines);
            }
        }
    }

    void GraphicInterface::draw()
    {
        m_window.clear(sf::Color(20, 20, 20));

        drawWires();
        
        for (auto &[name, component] : m_components) {
            component->draw(m_window);
        }

        m_window.draw(m_sliderBar);
        m_window.draw(m_sliderKnob);
        m_window.draw(m_sliderText);

        m_window.draw(m_simulateButton);
        m_window.draw(m_simulateText);

        m_window.display();
    }

    void GraphicInterface::handleMouseClick(const sf::Vector2i &mousePos)
    {
        sf::Vector2f worldPos = m_window.mapPixelToCoords(mousePos);

        if (m_simulateButton.getGlobalBounds().contains(worldPos)) {
            simulateAndCapture();
            return;
        }

        for (auto &[name, component] : m_components) {
            sf::FloatRect bounds(component->getPosition(), sf::Vector2f(120.f, 80.f));
            if (bounds.contains(worldPos)) {
                auto it = m_circuit._components.find(name);
                if (it != m_circuit._components.end()) {
                    nts::IComponent* logicalComp = it->second.get();

                    auto inputComp = dynamic_cast<nts::Input*>(logicalComp);
                    if (inputComp) {
                        nts::Tristate current = inputComp->compute(1);
                        nts::Tristate nextVal = (current == nts::True) ? nts::False : nts::True;
                        inputComp->setValue(nextVal);
                        component->setPinState(1, nextVal);
                        return;
                    }

                    auto clockComp = dynamic_cast<nts::Clock*>(logicalComp);
                    if (clockComp) {
                         nts::Tristate current = clockComp->compute(1);
                         nts::Tristate nextVal = (current == nts::True) ? nts::False : nts::True;
                         clockComp->setValue(nextVal);
                         component->setPinState(1, nextVal);
                         return;
                    }
                }
            }
        }
    }

    void GraphicInterface::run()
    {
        while (m_window.isOpen()) {
            sf::Event event;
            while (m_window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    m_window.close();
                }
                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                    handleMouseClick(sf::Mouse::getPosition(m_window));
                }
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                    m_window.close();
                }
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                    simulateAndCapture();
                }
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) {
                    if (m_displayTick < m_maxTick) {
                        m_displayTick++;
                        if (m_maxTick > 0) {
                            float ratio = static_cast<float>(m_displayTick) / static_cast<float>(m_maxTick);
                            m_sliderKnob.setPosition(30.f + ratio * 300.f, 24.f);
                        }
                    }
                }
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left) {
                    if (m_displayTick > 0) {
                        m_displayTick--;
                        if (m_maxTick > 0) {
                            float ratio = static_cast<float>(m_displayTick) / static_cast<float>(m_maxTick);
                            m_sliderKnob.setPosition(30.f + ratio * 300.f, 24.f);
                        }
                    }
                }

                handleSliderInput(event);
            }

            update();
            draw();
        }
    }

}
