#include "Bullet.hpp"

Bullet::Bullet(ColorType c, sf::Vector2f dir, ColorType playerColor, ColorType enemyColor, sf::Vector2f playerPos) {
    
    speed = 0.5f;
    
    bulletPos.x = playerPos.x + (shape.getRadius() / 2);
    bulletPos.y = playerPos.y + (shape.getRadius() / 2);

    color = c;

    if (dir.x == 0.f && dir.y == 0.f)
        dir = { 1.f, 0.f }; // default direction

    velocity = dir * speed;

    shape.setRadius(5.f);
    shape.setPosition(bulletPos);
    shape.setFillColor(toSFMLColor(color));

    dmg = 10 * getDamageMultiplier(playerColor, enemyColor);
}

void Bullet::update() {
    shape.move(velocity);
}

ColorType Bullet::getColor() {
    return color;
}