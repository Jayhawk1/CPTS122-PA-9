#include "Enemy.hpp"
//#include "Walker.hpp"

class SplitterEnemy : public Enemy {
public:
	SplitterEnemy(ColorType c, sf::Vector2f pos);

	void update() override; //The logic for Splitter in specific

	void onDeath();
private:
	float health = 1600;
	float moveSpeed = 0.04f;
};


inline SplitterEnemy::SplitterEnemy(ColorType c, sf::Vector2f pos)
{
	this->setColor(c);

	shape.setRadius(20.f);
	shape.setPosition(pos);
	shape.setFillColor(toSFMLColor(this->getColor()));
}

void SplitterEnemy::update() {
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

	this->health = this->health - 1;

	if (this->health < 1) {
		this->onDeath();
	}
	//std::cout << "SplitterEnemy update funct" << std::endl;
}

void SplitterEnemy::onDeath() {
	WalkerEnemy* walkerLeft = new WalkerEnemy(RED, this->shape.getPosition());
	WalkerEnemy* walkerRight = new WalkerEnemy(BLUE, this->shape.getPosition());

	this->parentList->insertEntity(*walkerLeft);
	this->parentList->insertEntity(*walkerRight);

	walkerLeft->setVelocity(sf::Vector2f(-30, 0));
	walkerRight->setVelocity(sf::Vector2f(30, 0));

	this->Enemy::onDeath();
}