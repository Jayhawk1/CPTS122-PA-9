#include "Bullet.hpp"

Bullet::Bullet(sf::Vector2f pos, ColorType c, sf::Vector2f dir) {
    color = c;
    velocity = dir;

    shape.setRadius(5.f);
    shape.setPosition(pos);
    shape.setFillColor(toSFMLColor(color));
}

void Bullet::update() {
    shape.move(velocity);
}

ColorType Bullet::getColor() {
    return color;
}