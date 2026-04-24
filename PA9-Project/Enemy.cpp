#include "Enemy.hpp"
#include"Color.hpp"

Enemy::Enemy(ColorType c, sf::Vector2f pos) {
    color = c;
    health = 100;
    moveSpeed = 0;

    shape.setRadius(15.f);
    shape.setPosition(pos);
    shape.setFillColor(toSFMLColor(color));
}

void Enemy::update() {
    // for now, enemy doesn't move
    std::cout << "Default enemy behavior" << std::endl;
}

float Enemy::getHealth()
{
    return this->health;
}

void Enemy::setHealth(float nHealth)
{
    this->health = nHealth;
}

void Enemy::takeDamage(ColorType bulletColor) {
    float dmg = 10 * getDamageMultiplier(bulletColor, color);
    health -= dmg;

    std::cout << "Enemy Health: " << health << std::endl;
}

void Enemy::setMoveSpeed(float nSpeed)
{
    this->moveSpeed = nSpeed;
}

float Enemy::getMoveSpeed()
{
    return this->moveSpeed;
}

ColorType Enemy::getColor() {
    return color;
}

void Enemy::setColor(ColorType nColor)
{
    this->color = nColor;
}

bool Enemy::alive() { return health > 0; }
