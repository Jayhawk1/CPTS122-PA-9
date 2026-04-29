#pragma once
#include "Color.hpp"

struct Projectile {
    sf::CircleShape shape;
    sf::Vector2f velocity;
    ColorType color;
    float damage;
};