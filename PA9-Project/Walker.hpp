#include "Enemy.hpp"

class WalkerEnemy : public Enemy {
public:
	WalkerEnemy(ColorType c, sf::Vector2f pos);

	void update() override; //The logic for walker in specific
private:
	float health = 50;
	float moveSpeed = 0.07f;
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

	Player* target = (Player*) this->getNearestEntityOfType(typeid(Player).name());

	sf::Vector2f targetDir = sf::Vector2f();
	//Move towards player
	if (target != nullptr) {
		targetDir = (target->getShape().getPosition() - this->shape.getPosition()).normalized();

		//std::cout << targetDir.x << ", " << targetDir.y << std::endl;
	}
	
	sf::Vector2f prevVelo = this->getVelocity();
	this->setVelocity((targetDir * moveSpeed) - (prevVelo * 0.16f));

	this->shape.move(this->getVelocity());

	//this->shape.setPosition(this->shape.getPosition() + this->getVelocity());

	//std::cout << "WalkerEnemy update funct" << std::endl;
}