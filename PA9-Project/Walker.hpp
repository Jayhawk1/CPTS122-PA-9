#pragma once
#include "Enemy.hpp"

class WalkerEnemy : public Enemy {
public:

	WalkerEnemy(ColorType c, sf::Vector2f pos)
	{
		this->setColor(c);
		getCircleShape().setRadius(15.f);
		getCircleShape().setPosition(pos);
		getCircleShape().setFillColor(toSFMLColor(this->getColor()));
	}

	void update(); //The logic for walker in specific
private:
	float health = 50;
	float moveSpeed = 0.07f;
};