#pragma once
#include <SFML/Graphics.hpp>

#include <iostream>

#include "Entity.hpp"
#include "Color.hpp"
#include "Player.hpp"

class Enemy : public Entity {
private:
    ColorType color;
    float health;
    float moveSpeed;
    sf::Vector2f velocity;
public:
    Enemy();
    Enemy(ColorType c, sf::Vector2f pos);
    ~Enemy();

    void update(); //Default behavior for an entity, should apply to every enemy

    float getHealth();
    void setHealth(float nHealth); //Directly set health for whatever purpose
    void takeDamage(ColorType bulletColor, float dmg);

    void onDeath(); //Should be called on death

    void setMoveSpeed(float nSpeed);
    float getMoveSpeed();

    void setVelocity(sf::Vector2f nVel);
    sf::Vector2f getVelocity();

    ColorType getColor();
    void setColor(ColorType nColor);
    bool alive();
};