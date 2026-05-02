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

    void setColor(ColorType color) {
        this->color = color;
		shape.setFillColor(toSFMLColor(color));
    }

    void setShape(sf::CircleShape shape) {
        this->shape = shape;
    }

	~Pickup() {
    }

};