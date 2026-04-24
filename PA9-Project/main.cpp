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

    WalkerEnemy enemy(BLUE, { 300, 200 });

    Pickup paint(RED, { 700, 500});

    while (window.isOpen()) {

        while (auto event = window.pollEvent()) {

            if (event->is<sf::Event::Closed>())
                window.close();

            if (event->is<sf::Event::KeyPressed>()) {
                if (event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::R)
                    player.swapColor();
            }
        }

        if (!player.getShape().getGlobalBounds().findIntersection(enemy.getShape().getGlobalBounds())) {
            iFrames = false;
        }

        player.update();
        enemy.update();

        if (player.getShape().getGlobalBounds().findIntersection(enemy.getShape().getGlobalBounds()) && !iFrames) {
            std::cout << "Collision detected!" << std::endl;
            player.takeDamage(enemy.getColor());
            iFrames = true;
        }

        if (player.getShape().getGlobalBounds().findIntersection(paint.getShape().getGlobalBounds())) {
            std::cout << "Collision detected!" << std::endl;
            player.newColor(paint.getColor());
        }

        window.clear();
        player.draw(window);
        enemy.draw(window);
        paint.draw(window);
        window.display();
    }
}