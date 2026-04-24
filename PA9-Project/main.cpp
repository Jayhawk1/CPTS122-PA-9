#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Enemy.hpp"
#include<iostream>

int main() {

    sf::RenderWindow window(sf::VideoMode({ 600, 400 }), "Game");

    Player player;

    Enemy enemy(BLUE, { 300, 200 });

    while (window.isOpen()) {

        while (auto event = window.pollEvent()) {

            if (event->is<sf::Event::Closed>())
                window.close();

            if (event->is<sf::Event::KeyPressed>()) {
                if (event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::R)
                    player.swapColor();
            }
        }

        player.update();
        enemy.update();

        if (player.getShape().getGlobalBounds().findIntersection(
            enemy.getShape().getGlobalBounds()))
        {
            std::cout << "Collision detected!" << std::endl;
        }

        window.clear();
        player.draw(window);
        enemy.draw(window);
        window.display();
    }
}