#pragma once
#include <SFML/Graphics.hpp>

#include <iostream>

#include "Entity.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Obstacle.hpp"

class Enemy : public Entity {
private:
    ColorType color;
    float health;
    float moveSpeed;
    sf::Vector2f velocity;
    sf::CircleShape shape;
public:
    Enemy();
    Enemy(ColorType c, sf::Vector2f pos);
    ~Enemy();

    void update(); //Default behavior for an entity, should apply to every enemy
    void Colupdate(std::vector<Obstacle>& obstacles);

    float getHealth();
    void setHealth(float nHealth); //Directly set health for whatever purpose
    void takeDamage(ColorType bulletColor, float dmg);

    void onDeath(); //Should be called on death

    void setMoveSpeed(float nSpeed);
    float getMoveSpeed();


    ColorType getColor();
    void setColor(ColorType nColor);
    bool alive();

    sf::Vector2f getVelocity() {
        return velocity;
    }

    void setVelocity(float dirx, float diry) {
        velocity.x = dirx;
        velocity.y = diry;
    }

    sf::Shape& getShape() override {
        return shape;
    }

    sf::CircleShape& getCircleShape() {
        return shape;
	}
};