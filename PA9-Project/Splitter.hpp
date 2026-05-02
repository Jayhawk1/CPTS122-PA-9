#pragma once
#include "Enemy.hpp"
//#include "Walker.hpp"

class SplitterEnemy : public Enemy {
public:
	SplitterEnemy(ColorType c, sf::Vector2f pos);

	void update(); //The logic for Splitter in specific

	void onDeath();


private:
	float health = 80;
	float moveSpeed = 0.04f;
};


inline SplitterEnemy::SplitterEnemy(ColorType c, sf::Vector2f pos)
{
	this->setColor(c);

	getCircleShape().setRadius(20.f);
	getCircleShape().setPosition(pos);
	getCircleShape().setFillColor(toSFMLColor(this->getColor()));
}

void SplitterEnemy::update() {
	this->Enemy::update(); //Call the default enemy behavior first

	Player* target = (Player*) this->getNearestEntityOfType(typeid(Player).name());

	sf::Vector2f targetDir = sf::Vector2f();
	//Move towards player
	if (target != nullptr) {
		targetDir = (target->getShape().getPosition() - this->getCircleShape().getPosition()).normalized();

		//std::cout << targetDir.x << ", " << targetDir.y << std::endl;
	}

	sf::Vector2f prevVelo = this->getVelocity();
	this->setVelocity((targetDir.x * moveSpeed) - (prevVelo.x * 0.16f), (targetDir.y * moveSpeed) - (prevVelo.y * 0.16f));

	this->getCircleShape().move(this->getVelocity());

	//this->shape.setPosition(this->shape.getPosition() + this->getVelocity());

	this->health = this->health - 1;

	if (this->health < 1) {
		this->onDeath();
	}
	//std::cout << "SplitterEnemy update funct" << std::endl;
}

void SplitterEnemy::onDeath() {
	WalkerEnemy* walkerLeft = new WalkerEnemy(RED, this->getCircleShape().getPosition());
	WalkerEnemy* walkerRight = new WalkerEnemy(BLUE, this->getCircleShape().getPosition());

	this->parentList->insertEntity(*walkerLeft);
	this->parentList->insertEntity(*walkerRight);

	walkerLeft->setVelocity(- 30.f, 0.f);
	walkerRight->setVelocity(30.f, 0.f);

	this->Enemy::onDeath();
}