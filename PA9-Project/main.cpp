#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Enemy.hpp"
#include "Pickup.hpp"

#include "Walker.hpp"

#include<iostream>

int main() {

    sf::RenderWindow window(sf::VideoMode({ 1280, 720 }), "Game");

    Player player;
    bool shot = false;

    WalkerEnemy enemy(BLUE, { 300, 200 });

    Pickup paint(RED, { 700, 500 });
    Pickup paint1(YELLOW, { 200, 800 });

    while (window.isOpen()) {

        while (auto event = window.pollEvent()) {

            if (event->is<sf::Event::Closed>())
                window.close();

            if (event->is<sf::Event::KeyPressed>()) {

                if (event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::R) {
                    player.swapColor();
                }
            }
        }



        //        if (!player.getShape().getGlobalBounds().findIntersection(enemy.getShape().getGlobalBounds())) {
          //          player.setIFrames(false);
      
    //}

        player.update(enemy);
        enemy.update();
        
 
    /*
        if (player.Collision(enemy) && !player.getIFrames()) {
            player.takeDamage(enemy.getColor());
            player.setIFrames(true);
		}


        */
        if(player.Collision(paint)) {
            player.newColor(paint.getColor());
        }

       // if()


        window.clear();

        if (player.alive()) {
            player.draw(window);
        }

        if (enemy.alive()) {
            enemy.draw(window);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !shot) {
 
            player.projectile(player.getCurrentColor(), { 0.f, -1.f }, enemy.getColor());
            shot = true;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !shot) {
            player.projectile(player.getCurrentColor(), { 0.f, 1.f }, enemy.getColor());
            shot = true;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && !shot) {
            player.projectile(player.getCurrentColor(), { -1.f, 0.f }, enemy.getColor());
            shot = true;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && !shot) {
            player.projectile(player.getCurrentColor(), { 1.f, 0.f },enemy.getColor());
            shot = true;
        }


        // do not allow a shooting more than once per key press
        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
            shot = false;
        }

        paint.draw(window);

        window.display();
    }
}