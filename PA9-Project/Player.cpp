#include "Player.hpp"
#include <iostream>


void Player::update(Enemy& enemy) {
    float speed = 0.2f;

    /*
        With how collision works in SFML (at least how we do it) the player can glitch through objects if they strafe
        while pressing against it (ex. holding A/D while holding W against a wall). This is because all we do to simulate "collision"
        is just reversing the speed applied to the players movement. In order to counteract this, all I did was disable the players ability
        to move in the direction of anything of an "Obstacle" class. Allowing strafing still allows them to just walk through it.
        You can still glitch through it by pressing like every key. I will likely impliment a killbox outside the map
    */

      //if (!isStunned) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && !isCollidingUp) {
            shape.move({ 0, -speed });
            lastDirection = UP;
			isCollidingDown = false;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && !isCollidingDown) {
            shape.move({ 0, speed });
            lastDirection = DOWN;
            isCollidingUp = false;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && !isCollidingLeft) {
            shape.move({ -speed, 0 });
            lastDirection = LEFT;;
            isCollidingRight = false;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && !isCollidingRight) {
            shape.move({ speed, 0 });
            lastDirection = RIGHT;
			isCollidingLeft = false;
        }
   // }

        if (playerStunClock.getElapsedTime().asSeconds() >= stunTime) {
            iFrames = false;
            //isStunned = false;
        }

        if (strafeClock.getElapsedTime().asSeconds() >= strafedisableTime) {
            isCollidingUp = false;
            isCollidingDown = false;
            isCollidingLeft = false;
            isCollidingRight = false;
		}


    if (health < 1) {
        // die
    }

    if (Collision(enemy) && lastDirection == NILL && !iFrames) {
        takeDamage(enemy.getColor());
        playerStunClock.restart();
        iFrames = true;
       // isStunned = true;
    }
    else if (Collision(enemy) && lastDirection != NILL) {
        
        if (!iFrames) {
            takeDamage(enemy.getColor());
            playerStunClock.restart();
            iFrames = true;
			//isStunned = true;
        }
/*                                         Too many movement bugs, teleporting / phasing when damged
        switch (lastDirection) {
        case UP:
            shape.move({ 0, speed*5 });
            isCollidingUp = true;
            break;
        case DOWN:
            shape.move({ 0, -speed*5 });
            isCollidingDown = true;
            break;
        case LEFT:                             /// Knockback handler
            shape.move({ speed*5, 0 });
            isCollidingLeft = true;
            break;
        case RIGHT:
            shape.move({ -speed*5, 0 });
            isCollidingRight = true;
            break;
        }
        */
	}

    


    updateProjectiles(enemy);
}


void Player::update(Room& room) {
    float speed = 0.2f;
    if (room.Collision(*this)) {
		strafeClock.restart();

            switch (lastDirection) {
            case UP:
                shape.move({ 0, speed * 2 });
				isCollidingUp = true;
                break;
            case DOWN:
                shape.move({ 0, -speed * 2 });
				isCollidingDown = true;
                break;
            case LEFT:
                shape.move({ speed * 2, 0 });
				isCollidingLeft = true;
                break;
            case RIGHT:
                shape.move({ -speed * 2, 0 });
				isCollidingRight = true;
                break;
            }
        }

}

void Player::update(Pickup& pickup) {
    if (Collision(pickup)) {
        newColor(pickup.getColor());

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


// Add obstacles to vector and periodically run through vector

void Player::updateProjectiles(Obstacle& obstacle) {

    for (auto& b : projectiles) {

        b.update();

        for (auto it = projectiles.begin(); it != projectiles.end();) {
            if (b.Collision(obstacle)) {
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
