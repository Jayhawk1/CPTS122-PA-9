#include "Enemy.hpp"
#include"Color.hpp"
#include <iostream>



Enemy::Enemy(ColorType c, sf::Vector2f pos) {
    color = c;
    health = 100;

    shape.setRadius(15.f);
    shape.setPosition(pos);
    shape.setFillColor(toSFMLColor(color));
}

void Enemy::update() {
    // for now, enemy doesn't move
}

void Enemy::takeDamage(ColorType bulletColor) {
    float dmg = 10 * getDamageMultiplier(bulletColor, color);
    health -= dmg;

    std::cout << "Enemy Health: " << health << std::endl;
}

ColorType Enemy::getColor() {
    return color;
}
