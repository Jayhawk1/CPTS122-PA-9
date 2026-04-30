#include "Player.hpp"
#include <iostream>


void Player::update(Enemy& enemy) {
    float speed = 0.2f;

      if (!isStunned) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            shape.move({ 0, -speed });
            lastDirection = UP;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            shape.move({ 0, speed });
            lastDirection = DOWN;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            shape.move({ -speed, 0 });
            lastDirection = LEFT;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            shape.move({ speed, 0 });
            lastDirection = RIGHT;
        }
    }

        if (playerStunClock.getElapsedTime().asSeconds() >= stunTime) {
            iFrames = false;
            isStunned = false;
        }

    if (health < 1) {
        // die
    }

    if (Collision(enemy) && lastDirection == NILL && !iFrames) {
        takeDamage(enemy.getColor());
        iFrames = true;
        isStunned = true;
    }
    else if (Collision(enemy) && lastDirection != NILL) {
        
        if (!iFrames) {
            takeDamage(enemy.getColor());
            playerStunClock.restart();
            iFrames = true;
			isStunned = true;
        }
        switch (lastDirection) {
        case UP:
            shape.move({ 0, speed*500 });
            break;
        case DOWN:
            shape.move({ 0, -speed*500 });
            break;
        case LEFT:
            shape.move({ speed*500, 0 });
            break;
        case RIGHT:
            shape.move({ -speed*500, 0 });
            break;
        }
	}




    updateProjectiles(enemy);
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







void Player::projectile(ColorType projectileColor, sf::Vector2f dir, ColorType enemyColor) {

    projectiles.emplace_back(Bullet(projectileColor, dir, getCurrentColor(), enemyColor, getPlayerPos()));
}


bool Player::alive() { return health > 0; }



void Player::updateProjectiles(Enemy& enemy) {

    for (auto& b : projectiles) {
		
        b.update();

		for (auto it = projectiles.begin(); it != projectiles.end();) {
            if (b.Collision(enemy)) {
                enemy.takeDamage(b.getColor(), b.getDamage());
                it = projectiles.erase(it);
            }
            else {
                ++it;
            }
        }
       
    }
}



void Player::draw(sf::RenderWindow& window) {
    window.draw(shape);

    for (auto& b : projectiles) {
        window.draw(b.getShape());
    }
}
