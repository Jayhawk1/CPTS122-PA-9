#include "Walker.hpp"
#include "Player.hpp"

void WalkerEnemy::update() {
    this->Enemy::update();

    Player* target = (Player*)this->getNearestEntityOfType(typeid(Player).name());

    sf::Vector2f targetDir = sf::Vector2f();
    if (target != nullptr) {
        targetDir = (target->getShape().getPosition() - this->shape.getPosition()).normalized();
    }

    sf::Vector2f prevVelo = this->getVelocity();
    this->setVelocity((targetDir * moveSpeed) - (prevVelo * 0.16f));

    this->shape.move(this->getVelocity());
}
