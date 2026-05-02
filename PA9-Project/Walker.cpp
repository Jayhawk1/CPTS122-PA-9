#include "Walker.hpp"
#include "Player.hpp"




void WalkerEnemy::update() {
	// 1. MUST check alive status before any logic
	if (!this->getIsAlive()) {
		return; // Stop the movement logic entirely if dead
	}

	this->Enemy::update(); //Call the default enemy behavior first

	Player* target = (Player*)this->getNearestEntityOfType(typeid(Player).name());

	sf::Vector2f targetDir = sf::Vector2f();
	//Move towards player
	if (target != nullptr) {
		targetDir = (target->getShape().getPosition() - this->getShape().getPosition()).normalized();

		//std::cout << targetDir.x << ", " << targetDir.y << std::endl;
	}

	sf::Vector2f prevVelo = this->getVelocity();
	this->setVelocity((targetDir.x * moveSpeed) - (prevVelo.x * 0.16f), (targetDir.y * moveSpeed) - (prevVelo.y * 0.16f));

	this->getShape().move(this->getVelocity());

	//this->shape.setPosition(this->shape.getPosition() + this->getVelocity());

	//std::cout << "WalkerEnemy update funct" << std::endl;
}