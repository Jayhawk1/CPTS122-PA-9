#pragma once
#include "Enemy.hpp"


class Player;

class WalkerEnemy : public Enemy {
public:
	WalkerEnemy(ColorType c, sf::Vector2f pos);

	void update(); //The logic for walker in specific
private:
	float health = 50;
	float moveSpeed = 0.07f;
};


