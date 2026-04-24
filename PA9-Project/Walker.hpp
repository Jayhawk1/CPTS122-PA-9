#include "Enemy.hpp"

class WalkerEnemy : public Enemy {
public:
	WalkerEnemy(ColorType c, sf::Vector2f pos);

	void update() override; //The logic for walker in specific
private:
	float health = 50;
	float moveSpeed = 0.1f;
};


inline WalkerEnemy::WalkerEnemy(ColorType c, sf::Vector2f pos)
{
	this->setColor(c);

	shape.setRadius(15.f);
	shape.setPosition(pos);
	shape.setFillColor(toSFMLColor(this->getColor()));
}

void WalkerEnemy::update() {
	this->Enemy::update(); //Call the default enemy behavior first

	//std::cout << "WalkerEnemy update funct" << std::endl;
}