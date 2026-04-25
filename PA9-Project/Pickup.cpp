#include "Pickup.hpp"

Pickup::Pickup(ColorType c, sf::Vector2f pos) {
    color = c;

    shape.setRadius(10.f);

    shape.setPosition(pos);

    shape.setFillColor(toSFMLColor(color));
}

void Pickup::draw(sf::RenderWindow& window) {

    window.draw(shape);
}

ColorType Pickup::getColor() {

    return color;
}

sf::CircleShape& Pickup::getShape() {

    return shape;
}