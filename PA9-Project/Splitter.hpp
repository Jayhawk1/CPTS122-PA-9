#pragma once
#include "Enemy.hpp"
#include "Walker.hpp"

class SplitterEnemy : public Enemy {
public:

	SplitterEnemy(ColorType c, sf::Vector2f pos)
	{
		this->setColor(c);

		getCircleShape().setRadius(20.f);
		getCircleShape().setPosition(pos);
		getCircleShape().setFillColor(toSFMLColor(this->getColor()));
	}


	void update(); //The logic for Splitter in specific

	void onDeath();


private:
	float health = 80;
	float moveSpeed = 0.04f;
};


