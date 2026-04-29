#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Enemy.hpp"
#include "Pickup.hpp"
#include "Entity.hpp"

#include "Walker.hpp"
#include "Splitter.hpp"

#include <iostream>

int main() {
    EntityList<Entity> Entities = EntityList<Entity>();

    sf::RenderWindow window(sf::VideoMode({ 1280, 720 }), "Game");

    Player player;
    bool iFrames = false;

    WalkerEnemy* enemy = new WalkerEnemy(BLUE, { 300, 200 });

    SplitterEnemy* splitterEnemy = new SplitterEnemy(YELLOW, { 500, 200 });

    Entities.insertEntity(player);
    Entities.insertEntity(enemy);
    Entities.insertEntity(splitterEnemy);

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

        if (!player.getShape().getGlobalBounds().findIntersection(enemy->getShape().getGlobalBounds())) {
            iFrames = false;
        }

        //Update every entity in the entity list
        for (int i = 0; i < Entities.getEntityCount(); i++) {
            Entity* nEntity = Entities.getEntity(i);
            if (nEntity->getEnabled()) {
                nEntity->update();
            }
        }

        if (player.getShape().getGlobalBounds().findIntersection(enemy->getShape().getGlobalBounds()) && !iFrames) {
            std::cout << "Collision detected!" << std::endl;
            player.takeDamage(enemy->getColor());
            iFrames = true;
        }

        if (player.getShape().getGlobalBounds().findIntersection(paint.getShape().getGlobalBounds())) {
            std::cout << "Collision detected!" << std::endl;
            player.newColor(paint.getColor());
        }

        window.clear();

        //Update every entity in the entity list
        for (int i = 0; i < Entities.getEntityCount(); i++) {
            Entity* nEntity = Entities.getEntity(i);
            nEntity->draw(window);
        }

        paint.draw(window);
        window.display();
    }
}