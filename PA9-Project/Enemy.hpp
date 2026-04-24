#pragma once
#include <SFML/Graphics.hpp>

#include "Entity.hpp"
#include "Color.hpp"

class Enemy : public Entity {
private:
    ColorType color;
    float health;

public:
    Enemy(ColorType c, sf::Vector2f pos);

    void update() override;
    void takeDamage(ColorType bulletColor);
};