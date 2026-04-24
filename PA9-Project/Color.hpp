#pragma once
#include <SFML/Graphics.hpp>

enum ColorType { RED, BLUE, YELLOW, NONE };

inline sf::Color toSFMLColor(ColorType c) {
    switch (c) {
    case RED: return sf::Color::Red;
    case BLUE: return sf::Color::Blue;
    case YELLOW: return sf::Color::Yellow;
    case NONE: return sf::Color::White;
    }
    return sf::Color::White;
}

inline float getDamageMultiplier(ColorType bullet, ColorType enemy) {
    if (bullet == enemy) return 0.5f;
    return 1.0f;
}