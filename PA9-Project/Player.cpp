#include "Player.hpp"
#include <iostream>


Player::Player() {
    shape.setRadius(15.f);
    shape.setPosition({ 100, 100 });

    color1 = NONE;
    color2 = NONE;
    usingFirst = true;
    health = 100;


    shape.setFillColor(toSFMLColor(color1));
}

void Player::update() {
    float speed = 0.2f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        shape.move({ 0, -speed });
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        shape.move({ 0, speed });
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        shape.move({ -speed, 0 });
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        shape.move({ speed, 0 });

    if (health < 1) {
        // die
    }
}

void Player::swapColor() {
    usingFirst = !usingFirst;
    shape.setFillColor(toSFMLColor(getCurrentColor()));
}

void Player::newColor(ColorType newColor) {
    if (usingFirst) { color1 = newColor; }
    else { color2 = newColor; }
}

ColorType Player::getCurrentColor() {
    return usingFirst ? color1 : color2;
}

void Player::takeDamage(ColorType enemyColor) {

    ColorType color;

    if (usingFirst) { color = color1; }
    else { color = color2; }

    float dmg = 10 * getDamageMultiplier(enemyColor, color);
    health -= dmg;

    std::cout << "Player Health: " << health << std::endl;
}

bool Player::alive() { return health > 0; }

