#pragma once
#include <SFML/Graphics.hpp>
#include "Color.hpp"
#include "Entity.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"


class Player : public Entity {
private:
    ColorType color1, color2;
    bool usingFirst;
    float health;
    std::vector<Bullet> projectiles;
    sf::Vector2f playerPos; 
    float stunTime;
    sf::Clock playerStunClock;
    bool isStunned;

    enum Directon {
        NILL = 0,
        UP = 1,
        DOWN = 2,
        LEFT = 3,
        RIGHT = 4
    };

    int lastDirection;

public:

    Player() {
        shape.setRadius(15.f);
        shape.setPosition({ 100, 100 });

        color1 = NONE;
        color2 = NONE;
        usingFirst = true;
        health = 100;

        shape.setFillColor(toSFMLColor(color1));

        playerPos = shape.getPosition();

        lastDirection = NILL;

        stunTime = 1.0f;

        isStunned = false;

        
    }

    ~Player() {

    }


    void draw(sf::RenderWindow& window);
    void updateProjectiles(Enemy& enemy);
    void update(Enemy& enemy);
    void swapColor();
    void newColor(ColorType newColor);
    ColorType getCurrentColor();
    void takeDamage(ColorType enemyColor);
    void projectile(ColorType projectileColor, sf::Vector2f dir, ColorType enemyColor);
    bool alive();

    sf::Vector2f getPlayerPos(){

		playerPos = shape.getPosition();

        return playerPos;
	}

    void forceStunStop() {
        playerStunClock.stop();
        isStunned = false;
    }


    void setPlayerPos(float newX, float newY) {
        playerPos.x = newX;
        playerPos.y = newY;
    }
   
};