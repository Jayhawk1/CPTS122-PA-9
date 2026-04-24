#pragma once
#include <SFML/Graphics.hpp>

#include <iostream>

#include "Entity.hpp"
#include "Color.hpp"

class Enemy : public Entity {
private:
    ColorType color;
    float health;
    float moveSpeed;
public:
    Enemy(ColorType c, sf::Vector2f pos);

    void update() override; //Default behavior for an entity, should apply to every enemy

    float getHealth();
    void setHealth(float nHealth); //Directly set health for whatever purpose
    void takeDamage(ColorType bulletColor);

    void setMoveSpeed(float nSpeed);
    float getMoveSpeed();

    ColorType getColor();
    void setColor(ColorType nColor);
};