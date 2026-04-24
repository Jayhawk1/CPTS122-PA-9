#include "Player.hpp"



Player::Player() {
    shape.setRadius(15.f);
    shape.setPosition({ 100, 100 });

    color1 = RED;
    color2 = BLUE;
    usingFirst = true;

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
}

void Player::swapColor() {
    usingFirst = !usingFirst;
    shape.setFillColor(toSFMLColor(getCurrentColor()));
}

ColorType Player::getCurrentColor() {
    return usingFirst ? color1 : color2;
}