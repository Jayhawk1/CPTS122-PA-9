#include "Enemy.hpp"
#include"Color.hpp"

Enemy::Enemy()
{
    color = ColorType::NONE;
    health = 100;
    moveSpeed = 0;
    shape.setRadius(15.f);
}

Enemy::Enemy(ColorType c, sf::Vector2f pos) {
    color = c;
    health = 100;
    moveSpeed = 0;
    velocity = sf::Vector2f();

    shape.setRadius(15.f);
    shape.setPosition(pos);
    shape.setFillColor(toSFMLColor(color));
}

Enemy::~Enemy()
{
    std::cout << "REMOVING ENEMY" << this->entityNum << std::endl;
    this->parentList->removeEntity(*this);
    this->parentList = nullptr;
}

void Enemy::update() {
    // for now, enemy doesn't move
    this->shape.move(this->velocity);
    //std::cout << "Default enemy behavior" << std::endl;
}

float Enemy::getHealth()
{
    return this->health;
}

void Enemy::setHealth(float nHealth)
{
    this->health = nHealth;
}

void Enemy::takeDamage(ColorType bulletColor, float dmg) {
    
    health -= dmg;

    std::cout << "Enemy Health: " << health << std::endl;
}

void Enemy::onDeath()
{
    //Any effects or whatever
    //if (this->parentList != nullptr) {
    //    this->parentList->removeEntity(this->entityNum);
    //}
    //this->~Enemy();
    delete this;
}

void Enemy::setMoveSpeed(float nSpeed)
{
    this->moveSpeed = nSpeed;
}

float Enemy::getMoveSpeed()
{
    return this->moveSpeed;
}

void Enemy::setVelocity(sf::Vector2f nVel)
{
    this->velocity = nVel;
}

sf::Vector2f Enemy::getVelocity()
{
    return this->velocity;
}

ColorType Enemy::getColor() {
    return color;
}

void Enemy::setColor(ColorType nColor)
{
    this->color = nColor;
}

bool Enemy::alive() { return health > 0; }

