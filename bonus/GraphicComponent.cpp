/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** GraphicComponent implementation
*/

#include "GraphicComponent.hpp"
#include <iostream>
#include <cmath>

namespace nts {

    GraphicComponent::GraphicComponent(const std::string &name, const sf::Vector2f &position, const sf::Font &font)
        : m_name(name), m_position(position), m_fontValid(true)
    {
        m_rect.setSize(sf::Vector2f(120.f, 80.f));
        m_rect.setPosition(position);
        m_rect.setFillColor(sf::Color(50, 50, 60));
        m_rect.setOutlineThickness(2.f);
        m_rect.setOutlineColor(sf::Color::White);

        m_label.setFont(font);
        m_label.setString(name);
        m_label.setCharacterSize(12);
        m_label.setFillColor(sf::Color::White);
        
        sf::FloatRect bounds = m_label.getLocalBounds();
        m_label.setPosition(
            position.x + (120.f - bounds.width) / 2.f,
            position.y + (80.f - bounds.height) / 2.f
        );

        createPins(font);
    }

    void GraphicComponent::createPins(const sf::Font &font)
    {
        const int totalPins = 14;
        float pinsPerSide = totalPins / 2.0f;
        float spacing = 80.f / (pinsPerSide + 1);

        for (int i = 1; i <= totalPins; ++i) {
            Pin pin;
            pin.id = i;
            pin.state = nts::Undefined;
            pin.shape.setRadius(3.f);
            pin.shape.setOrigin(3.f, 3.f);
            pin.shape.setFillColor(sf::Color(100, 100, 100));

            pin.label.setFont(font);
            pin.label.setString(std::to_string(i));
            pin.label.setCharacterSize(8);
            pin.label.setFillColor(sf::Color::Cyan);

            if (i <= 7) {
                pin.isOutput = false;
                float y = m_position.y + spacing * i;
                pin.shape.setPosition(m_position.x, y);
                pin.label.setPosition(m_position.x - 10.f, y - 4.f);
            } else {
                pin.isOutput = true;
                int rightIdx = i - 7;
                float y = m_position.y + spacing * (8 - rightIdx);
                pin.shape.setPosition(m_position.x + 120.f, y);
                pin.label.setPosition(m_position.x + 125.f, y - 4.f);
            }

            m_pins[i] = pin;
        }
    }

    void GraphicComponent::setPinState(std::size_t pinId, nts::Tristate state)
    {
        auto it = m_pins.find(pinId);
        if (it != m_pins.end()) {
            it->second.state = state;
            it->second.shape.setFillColor(getStateColor(state));
        }
    }

    sf::Color GraphicComponent::getStateColor(nts::Tristate state)
    {
        if (state == nts::True) return sf::Color::Green;
        if (state == nts::False) return sf::Color::Red;
        return sf::Color(100, 100, 100);
    }

    void GraphicComponent::draw(sf::RenderWindow &window)
    {
        window.draw(m_rect);
        window.draw(m_label);
        for (auto& [id, pin] : m_pins) {
            window.draw(pin.shape);
            window.draw(pin.label);
        }
    }

    sf::Vector2f GraphicComponent::getPinPosition(std::size_t pinId) const
    {
        auto it = m_pins.find(pinId);
        if (it != m_pins.end()) {
            return it->second.shape.getPosition();
        }
        return m_position;
    }

}

