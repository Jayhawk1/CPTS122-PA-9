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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        lastDirection = { 0.f, -1.f };
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        lastDirection = { 0.f, 1.f };
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        lastDirection = { -1.f, 0.f };
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        lastDirection = { 1.f, 0.f };

    updateProjectiles();
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







void Player::projectile(ColorType projectilColor) {

void Player::projectile(ColorType projectilColor, sf::Vector2f dir) {
    ColorType color;

    if (usingFirst) { color = color1; }
    else { color = color2; }

    float dmg = 10 * getDamageMultiplier(projectilColor, color);

   
    Projectile p;
    sf::Vector2f playerPos = shape.getPosition();
    playerPos.x = playerPos.x + (shape.getRadius() / 2);
    playerPos.y = playerPos.y + (shape.getRadius() / 2);

    p.shape.setRadius(5.f);
    p.shape.setPosition(shape.getPosition());
    p.shape.setFillColor(toSFMLColor(projectilColor));


   

    sf::Vector2f dir = lastDirection;

    if (dir.x == 0.f && dir.y == 0.f)
        dir = { 1.f, 0.f }; // default direction

    float speed = 0.5f;
    p.velocity = dir * speed;

    

    p.damage = dmg;
    p.color = projectilColor;

    projectiles.push_back(p);
}

bool Player::alive() { return health > 0; }



void Player::updateProjectiles() {

    for (auto& p : projectiles) {
        //if(p.shape.getPosition() == enemy position){ delete projectile and damage enemy
        p.shape.move(p.velocity);
    }
}



void Player::draw(sf::RenderWindow& window) {
    window.draw(shape);

    for (auto& p : projectiles) {
        window.draw(p.shape);
    }
}