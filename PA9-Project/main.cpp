#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Enemy.hpp"
#include "Pickup.hpp"

#include "Walker.hpp"

#include<iostream>

int main() {

    sf::RenderWindow window(sf::VideoMode({ 1280, 720 }), "Game");

    Player player;
    bool iFrames = false;
    bool shot = false;

    WalkerEnemy enemy(BLUE, { 300, 200 });

    Pickup paint(RED, { 700, 500 });
    Pickup paint1(YELLOW, { 200, 600 });

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




        if (!player.getShape().getGlobalBounds().findIntersection(enemy.getShape().getGlobalBounds())) {
            iFrames = false;
        }

        player.update();
        enemy.update();


        // Enemy collision
        if (player.getShape().getGlobalBounds().findIntersection(enemy.getShape().getGlobalBounds()) && !iFrames) {
            std::cout << "Collision detected!" << std::endl;
            player.takeDamage(enemy.getColor());
            iFrames = true;
        }

        // Pickup collison
        if (player.getShape().getGlobalBounds().findIntersection(paint.getShape().getGlobalBounds())) {
            std::cout << "Collision detected!" << std::endl;
            player.newColor(paint.getColor());
            
        }
        if (player.getShape().getGlobalBounds().findIntersection(paint1.getShape().getGlobalBounds())) {
            std::cout << "Collision detected!" << std::endl;
            player.newColor(paint1.getColor());

        }


        window.clear();

        if (player.alive()) {
            player.draw(window);
        }

        if (enemy.alive()) {
            enemy.draw(window);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !shot) {
            player.projectile(player.getCurrentColor(), { 0.f, -1.f });
            shot = true;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !shot) {
            player.projectile(player.getCurrentColor(), { 0.f, 1.f });
            shot = true;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && !shot) {
            player.projectile(player.getCurrentColor(), { -1.f, 0.f });
            shot = true;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && !shot) {
            player.projectile(player.getCurrentColor(), { 1.f, 0.f });
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
        paint1.draw(window);

        window.display();
    }
}