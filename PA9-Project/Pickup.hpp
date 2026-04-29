#pragma once
#include <SFML/Graphics.hpp>
#include "Color.hpp"

class Pickup {
private:

    sf::CircleShape shape;
    ColorType color;

public:
    Pickup(ColorType c, sf::Vector2f pos);

    void draw(sf::RenderWindow& window);

    ColorType getColor();
    sf::CircleShape& getShape();
};