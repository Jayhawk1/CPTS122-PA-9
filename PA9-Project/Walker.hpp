#include "Enemy.hpp"

class WalkerEnemy : public Enemy {
public:
	void update() override; //The logic for walker in specific
private:
	float health = 50;
	float moveSpeed = 0.1f;
};

void WalkerEnemy::update() {
	this->Enemy::update(); //Call the default enemy behavior first

	std::cout << "WalkerEnemy update funct" << std::endl;
}