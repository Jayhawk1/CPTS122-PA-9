#pragma once
#include <SFML/Graphics.hpp>
#include"Entity.hpp"
#include"Color.hpp"

class Bullet : public Entity {
private:
    sf::Vector2f velocity;
    ColorType color;
    float dmg;
    sf::Vector2f bulletPos;
    float speed;

public:
    Bullet(ColorType c, sf::Vector2f dir, ColorType playerColor, ColorType enemyColor, sf::Vector2f PlayerPos);

    void update();

    ColorType getColor();

    float getDamage() {
		return dmg;
    }

    sf::Vector2f getBulletPos() {
        bulletPos = shape.getPosition();
        return bulletPos;
	}

    ~Bullet() {

		std::cout << "Bullet destroyed" << std::endl;

    }

    sf::Vector2f getBulletVelocity() {
          return velocity;
	}


    void setColor(ColorType nColor);
	void setDamage(float nDmg);
    void setBulletPos(float newX, float newY) {
        bulletPos.x = newX;
        bulletPos.y = newY;
	}

    
};